// Copyright 2020 Thomas.Hoehenleitner [at] seerose.net
// Use of this source code is governed by a license that can be found in the LICENSE file.

package id

// source tree management

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"reflect"
	"regexp"
	"strings"

	"github.com/rokath/trice/pkg/msg"
	"github.com/spf13/afero"
)

const (

	// patSourceFile is a regex pattern matching any source file for patching
	patSourceFile = "(\\.c|\\.h|\\.cc|\\.cpp|\\.hpp)$"

	// patSourceFile is a regex pattern matching any source file for patching
	patCFile = "(\\.c|\\.cc|\\.cpp)$"

	// patTrice matches any TRICE name variant  The (?i) says case-insensitive. (?U)=un-greedy -> only first match.
	patTypNameTRICE = `(?iU)(\b((TRICE((0|_0|AssertTrue|AssertFalse)|((8|16|32|64)*(_[0-9|S|N|B|F]*)*))))\b)` // https://regex101.com/r/vJn59K/1
	//                `(?iU)(\b((TRICE((0|_0)|((8|16|32|64)*(_[0-9|S|N|B|F]*)*))))\b)` // https://regex101.com/r/vJn59K/1
	//                `(?iU)(\b((TRICE((_(S|N|B|F)|0)|((8|16|32|64)*(_[0-9]*)*))))\b)` // https://regex101.com/r/IkIhV3/1
	//                `     (\b((TRICE(_S|0|(8|16|32|64)*)))(_[1-9]*)*|\b)\s*\(\s*\bID\b\s*\(\s*.*[0-9]\s*\)\s*,\s*".*"\s*.*\)\s*;` // https://regex101.com/r/pPRsjf/1
	//                `(?iU)(\b((TRICE(|_S|_N|(8|16|32|64)?_B|(8|16|32|64)?_F|0|(8|16|32|64)_*[0-9]*)))\b)`

	// patMatchingParentheses is finding matching parentheses
	//patMatchingParentheses = `(?U)\([^)(]*+(?:(?R)[^)(]*)*+\)` // https://regex101.com/r/eBtSTM/1

	// patNbID is a regex pattern matching any first "Id(n)" and usable in matches after patTypNameTRICE. It works also over line breaks.
	patNbID = `(?Ui)\b(i)(D)\b\s*\(\s*\d+\s*\)` // https://regex101.com/r/2BlNSv/1

	// patFmtString is a regex matching the first format string inside trice even containing newlines and \"
	patFmtString = `"(?s)(.*)"` // https://stackoverflow.com/questions/159118/how-do-i-match-any-character-across-multiple-lines-in-a-regular-expression

	// patNbTRICE is a regex pattern matching any "TRICE*(Id(n), "", ... )". - see https://regex101.com/r/mllhNQ/1
	// https://regex101.com/r/4hz1r8/1
	patNbTRICE = patTypNameTRICE + `\s*\(` + patID + `\(\s*.*[0-9]\s*\)\s*,\s*` + patFmtString + `\s*.*\)`

	// https://regex101.com/r/hWMjhU/3 - match any kind of trice with or without len or ID
	patFullAnyTrice = patTypNameTRICE + `\s*\(\s*(` + patID + `\((\s*\d+)\s*\)\s*,)?\s*` + patFmtString + `\s*.*\)`

	// patAnyTriceStart finds a starting trice with opening '(': https://regex101.com/r/wPuT4M/1
	patAnyTriceStart = patTypNameTRICE + `\s*\(`

	// patNextFormatSpecifier is a regex to find next format specifier in a string (exclude %%*)
	patNextFormatSpecifier = `(?:^|[^%])(%[0-9\.#]*(b|c|d|e|f|g|E|F|G|h|i|l|L|n|o|O|p|q|t|u|x|X))`

	// patTriceNoLen finds next `TRICEn` without length specifier: https://regex101.com/r/vSvOEc/1
	patTriceNoLen = `(?i)(\bTRICE(|8|16|32|64)\b)`

	patID = `\s*\b(i|I)(d|D)\b\s*` // `\s*\b(I|i)d\b\s*`

	//patNumber = `\d+`

	patNb = `\d+` // // `[0-9]*`

	// patIdInsideTrice finds if an `( Id(n) ,"` sequence exists inside trice
	patIDInsideTrice = `(?U)\(` + patID + `\((\s*\d+)\s*\)\s*,\s*"`

	//patIncludeTriceHeader = `#include\s*"trice\.h"`
)

var (
	matchSourceFile          = regexp.MustCompile(patSourceFile)
	matchNbTRICE             = regexp.MustCompile(patNbTRICE)
	matchNbID                = regexp.MustCompile(patNbID)
	matchNb                  = regexp.MustCompile(patNb)
	matchTypNameTRICE        = regexp.MustCompile(patTypNameTRICE)
	matchFmtString           = regexp.MustCompile(patFmtString)
	matchNextFormatSpecifier = regexp.MustCompile(patNextFormatSpecifier)
	matchFullAnyTrice        = regexp.MustCompile(patFullAnyTrice)
	matchTriceNoLen          = regexp.MustCompile(patTriceNoLen)
	matchIDInsideTrice       = regexp.MustCompile(patIDInsideTrice)
	matchAnyTriceStart       = regexp.MustCompile(patAnyTriceStart)
	//matchNumber              = regexp.MustCompile(patNumber)
	//matchIncludeTriceHeader  = regexp.MustCompile(patIncludeTriceHeader)

	ExtendMacrosWithParamCount bool

	// DefaultTriceBitWidth tells the bit width of TRICE macros having no bit width in their names, like TRICE32 or TRICE8.
	//
	// One target can use only one bith width for bare TRICE macros and the setting inside the target code must match DefaultTriceBitWidth.
	DefaultTriceBitWidth = "32" // todo: create compiler switch for other options "8", "16", "32", "64"
	DefaultStampSize     = 32
	StampSizeId          string
)

// updateParamCountAndID0 stays in text as long as trice statements are found.
// If a TRICE* is found, it is getting an Id(0) inserted, and it is also extended by _n.
// according to the format specifier count inside the format-string. Both only if not already existent.
// A none with the format specifier count matching _n is intentionally not corrected.
// About a not matching parameter count the C compiler will complain later.
// trice statements ending with letter 'i' keep the 'i' at the end.
// Short *Trices* like Trice0 or Trice16_1i need to have an id(0) instead of Id(0) but that gets corrected
// automatically when the id n is inserted.
// text is the full file contents, which could be modified, therefore it is also returned with a modified flag
func updateParamCountAndID0(w io.Writer, text string, extendMacroName bool) (string, bool) {
	var modified bool
	subs := text[:] // create a copy of text and assign it to subs
	for {
		loc := matchFullAnyTrice.FindStringIndex(subs) // find the next TRICE location in file
		if nil == loc {
			return text, modified // done
		}
		trice := subs[loc[0]:loc[1]] // the whole TRICE*(*);
		triceC := trice              // make a copy
		if extendMacroName {
			locNoLen := matchTriceNoLen.FindStringIndex(trice) // find the next TRICE no len location in trice
			if nil != locNoLen {                               // need to add len to trice name
				n := formatSpecifierCount(triceC)
				triceNameNoLen := triceC[locNoLen[0]:locNoLen[1]]
				triceNameWithLen := addFormatSpecifierCount(w, triceNameNoLen, n)
				// In this example `Trice8_1( id(  800), "rd:Trice8 line %d, %d\n", __LINE__, 2 );` triceNameNoLen is "Trice8",
				// that is the Trice8 after "rd:" and triceNameWithLen is Trice8_1.
				// The following line would replace the first `Trice8` which is part of `Trice8_1` with `Trice8_1` resulting in
				// `Trice8_1_1( id(  800), "rd:Trice8 line %d, %d\n", __LINE__, 2 );` what is a bug.
				// triceC = strings.Replace(triceC, triceNameNoLen, triceNameWithLen, 1) // insert _n
				// Therefore the replacement is donne manually:
				triceC = triceC[:locNoLen[0]] + triceNameWithLen + triceC[locNoLen[1]:] // insert _n
				modified = true
				if Verbose {
					fmt.Fprint(w, triceNameNoLen)
					fmt.Fprint(w, " -> ")
					fmt.Fprintln(w, triceNameWithLen)
				}
			}
		}
		// here trice name in triceC contains _n and now we need to check for Id existence.
		// triceC could have been modified here but text is unchanged so far.
		idLoc := matchIDInsideTrice.FindStringIndex(triceC)
		if nil == idLoc { // no Id(n) inside trice, so we add it
			triceO := matchAnyTriceStart.FindString(triceC) // TRICE*( part (the trice start)
			var triceU string
			if strings.Contains(triceO, "ice") {
				triceU = triceO + " iD(0),"
			} else {
				triceU = triceO + StampSizeId
			}
			triceC = strings.Replace(triceC, triceO, triceU, 1) // insert Id(0) into trice copy
			modified = true
			if Verbose {
				fmt.Fprint(w, triceO)
				fmt.Fprint(w, " -> ")
				fmt.Fprintln(w, triceU)
			}
		}
		if modified {
			text = strings.Replace(text, trice, triceC, 1) // this works, because a trice gets changed only once
		}
		subs = subs[loc[1]:] // The replacement makes text not shorter, so next search can start at loc[1]
	}
}

// formatSpecifierCount parses s for format specifier and returns the found count.
func formatSpecifierCount(s string) (count int) {
	xs := "any"
	for xs != "" {
		lo := matchNextFormatSpecifier.FindStringIndex(s)
		xs = matchNextFormatSpecifier.FindString(s)
		if xs != "" { // found
			count++
			s = s[lo[1]:]
		} else {
			xs = ""
		}
	}
	return
}

// addFormatSpecifierCount extends s with _n and returns it as sl
func addFormatSpecifierCount(w io.Writer, s string, n int) (sl string) {
	if 0 < n && n < 99 { // patch
		sl = fmt.Sprintf(s+"_%d", n) // TRICE*_n
	} else {
		if n != 0 {
			fmt.Fprintln(w, "Parse error: ", n, " % format specifier found inside ", s)
		}
		sl = s
	}
	return
}

func isSourceFile(fi os.FileInfo) bool {
	return matchSourceFile.MatchString(fi.Name())
}

func refreshList(w io.Writer, fSys *afero.Afero, root string, ilu TriceIDLookUp, flu triceFmtLookUp, lim TriceIDLookUpLI) {
	if Verbose {
		fmt.Fprintln(w, "dir=", root)
		fmt.Fprintln(w, "List=", FnJSON)
	}
	msg.FatalInfoOnErr(filepath.Walk(root, visitRefresh(w, fSys, ilu, flu, lim)), "failed to walk tree")
}

// Additional actions needed: (Option -dry-run lets do a check in advance.)
// - Insert in all TRICE messages without ID an `Id(0),`
// - Check if all TRICE messages have correct parameter count and adapt the count without touching the Id(n),
// - Check if ID list has same ID more than one time and remove younger items with message.
//  - Read til.json in a map and write til.json after the map was finally manipulated back to til.json.
// - Check if Source tree has same ID with different TRICE strings.
//   - Keep the ID which is in til.json and set others to 0 with message.
//   - If none of the more than 1 time used ID is in til.json set all to 0 with message.
// - Check if in source code exist IDs not in til.json so far and extend til.json if there is no conflict.
//  - If the ID in source code is already used in til.json differently set the ID in source code to 0 with message.
// NOT NEEDED: - Check if in til.json ID's not in source tree and mark them with `removed` timestamp.
// NOT NEEDED:   - If several source trees use same til.json, the `removed` timestamp is without sense.
// NOT NEEDED:   - If a `removed` timestamp is set, but the ID is in the source tree the `removed` timestamp is set to 0.

// idsUpdate is parsing source tree root which is part of Srcs and performing these actions:
// - replace.Type( Id(0), ...) with.Type( Id(n), ...)
// - find duplicate.Type( Id(n), ...) and replace one of them if *Trices* are not identical
// - extend file fnIDList
func idsUpdate(w io.Writer, fSys *afero.Afero, root string, ilu TriceIDLookUp, flu triceFmtLookUp, pListModified *bool, lim TriceIDLookUpLI) {
	if Verbose && FnJSON != "emptyFile" {
		fmt.Fprintln(w, "dir=", root)
		fmt.Fprintln(w, "List=", FnJSON)
	}
	msg.FatalInfoOnErr(fSys.Walk(root, visitUpdate(w, fSys, ilu, flu, pListModified, lim)), "failed to walk tree")
}

func readFile(w io.Writer, fSys *afero.Afero, path string, fi os.FileInfo, err error) (string, error) {
	if err != nil || fi.IsDir() || !isSourceFile(fi) {
		return "", err // forward any error and do nothing
	}
	if Verbose {
		fmt.Fprintln(w, path)
	}
	read, err := fSys.ReadFile(path)
	if nil != err {
		return "", err
	}
	text := string(read)
	return text, nil
}

func visitRefresh(w io.Writer, fSys *afero.Afero, ilu TriceIDLookUp, flu triceFmtLookUp, lim TriceIDLookUpLI) filepath.WalkFunc {
	return func(path string, fi os.FileInfo, err error) error {
		text, err := readFile(w, fSys, path, fi, err)
		if nil != err {
			return err
		}
		refreshIDs(w, path, text, ilu, flu, lim) // update ilu & lim
		return nil
	}
}

func isCFile(path string) bool {
	s := strings.ToLower(path)
	if strings.HasSuffix(s, patCFile) {
		fmt.Println(patCFile, "works")
		return true
	}
	if strings.HasSuffix(s, ".c") {
		return true
	}
	if strings.HasSuffix(s, ".cpp") {
		return true
	}
	if strings.HasSuffix(s, ".cxx") {
		return true
	}
	return false
}

func visitUpdate(w io.Writer, fSys *afero.Afero, ilu TriceIDLookUp, flu triceFmtLookUp, pListModified *bool, lim TriceIDLookUpLI) filepath.WalkFunc {
	// WalkFunc is the type of the function called for each file or directory
	// visited by Walk. The path argument contains the argument to Walk as a
	// prefix; that is, if Walk is called with "dir", which is a directory
	// containing the file "a", the walk function will be called with argument
	// "dir/a". The info argument is the os.FileInfo for the named path.
	//
	// If there was a problem walking to the file or directory named by path, the
	// incoming error will describe the problem and the function can decide how
	// to handle that error (and Walk will not descend into that directory). In the
	// case of an error, the info argument will be nil. If an error is returned,
	// processing stops. The sole exception is when the function returns the special
	// value SkipDir. If the function returns SkipDir when invoked on a directory,
	// Walk skips the directory's contents entirely. If the function returns SkipDir
	// when invoked on a non-directory file, Walk skips the remaining files in the
	// containing directory.
	return func(path string, fi os.FileInfo, err error) error {
		text, err := readFile(w, fSys, path, fi, err)
		if nil != err {
			return err
		}
		fileName := filepath.Base(path)

		// todo: each file is parsed 3 times -> put this in one function
		textN, fileModified0 := updateParamCountAndID0(w, text, ExtendMacrosWithParamCount)                                           // update parameter count: TRICE* to TRICE*_n
		textU, fileModified1 := updateIDsUniqOrShared(w, false /*SharedIDs*/, Min, Max, SearchMethod, textN, ilu, flu, pListModified) // update IDs: Id(0) -> Id(M)
		refreshIDs(w, fileName, textU, ilu, flu, lim)                                                                                 // workaround: do it again to update li.json.

		// write out
		fileModified := fileModified0 || fileModified1 /*|| fileModified2*/
		if fileModified && !DryRun {
			if Verbose {
				fmt.Fprintln(w, "Changed: ", path)
			}
			err = fSys.WriteFile(path, []byte(textU), fi.Mode())
			if nil != err {
				return fmt.Errorf("failed to change %s: %v", path, err)
			}
		}
		return nil
	}
}

// triceIDParse returns an extracted id and found as true if t starts with s.th. like 'TRICE*( Id(n)...'
// nbID is the extracted string part containing 'Id(n)'.
func triceIDParse(t string) (nbID string, id TriceID, found idType) {
	nbID = matchNbID.FindString(t)
	if nbID == "" {
		msg.InfoOnTrue(Verbose, fmt.Sprintln("No 'Id(n)' or 'id(n)' found inside "+t)) // todo: patID
		return
	}
	var n int
	_, err := fmt.Sscanf(nbID, "iD(%d", &n) // closing bracket in format string omitted intentionally // todo: patID
	if nil == err {                         // because spaces after id otherwise are not tolerated
		id = TriceID(n)
		found = idTypeS8
		return
	}
	_, err = fmt.Sscanf(nbID, "ID(%d", &n) // closing bracket in format string omitted intentionally // todo: patID
	if nil == err {                        // because spaces after id otherwise are not tolerated
		id = TriceID(n)
		found = idTypeS4
		return
	}
	_, err = fmt.Sscanf(nbID, "Id(%d", &n) // closing bracket in format string omitted intentionally // todo: patID
	if nil == err {                        // because spaces after id otherwise are not tolerated
		id = TriceID(n)
		found = idTypeS2
		return
	}
	_, err = fmt.Sscanf(nbID, "id(%d", &n) // closing bracket in format string omitted intentionally // todo: patID
	if nil == err {                        // because spaces after id otherwise are not tolerated
		id = TriceID(n)
		found = idTypeS0
		return
	}
	msg.Info(fmt.Sprintln("no 'Id(n' found inside " + nbID)) // todo: patID
	return
}

// triceFmtParse returns an extracted tf and found as true if t is s.th. like 'TRICE*( Id(n), "..." );'.
func triceFmtParse(t string) (tf TriceFmt, found bool) {
	tf.Type = matchTypNameTRICE.FindString(t)
	if tf.Type == "" {
		msg.Info(fmt.Sprintln("no 'TRICE*' found inside " + t))
		return
	}
	match := matchFmtString.FindAllStringSubmatch(t, 1)
	if nil == match {
		msg.Info(fmt.Sprintln("no 'trice format string' found inside " + t))
		return
	}
	tf.Strg = match[0][1]
	found = true
	return
}

//  func lineCount(text string) {
//
//  }

// triceParse expects a string t containing a trice macro in the form `TRICE*(Id(n), "...", ...);`
// Returned nbID is the extracted string part containing 'Id(n)'.
// Returned id is the scanned n inside Id(n), only and only if n is a single decimal number.
// Returned tf is the recognized trice.
// Only on success found is true.
func triceParse(t string) (nbID string, id TriceID, tf TriceFmt, found idType) {
	nbID, id, found = triceIDParse(t)
	//if found == idTypeS8 {
	//	return
	//}
	tf, ok := triceFmtParse(t)
	if !ok {
		msg.Info(fmt.Sprintln("triceFmtParse reported !ok inside " + t))
	}
	return
}

// refreshIDs parses text for valid trices tf and adds them to ilu & flu and updates location information map lim.
func refreshIDs(w io.Writer, fileName, text string, ilu TriceIDLookUp, flu triceFmtLookUp, lim TriceIDLookUpLI) {
	subs := text[:] // create a copy of text and assign it to subs
	line := 1       // source code lines start with 1 for some reason
	var li TriceLI
	li.File = filepath.Base(fileName)
	for {
		loc := matchNbTRICE.FindStringSubmatchIndex(subs) // find the next TRICE location in file
		if nil == loc {
			return // done
		}
		line += strings.Count(subs[:loc[0]], "\n")
		nbTRICE := subs[loc[0]:loc[1]] // full trice expression with Id(n)
		// prepare subs for next loop
		subs = subs[loc[1]:] // A possible Id(0) replacement makes subs not shorter, so next search can start at loc[1].
		// A case like 'TRICE*( Id(                             0                              ), "");' is not expected.

		_, id, tf, _ /*found*/ := triceParse(nbTRICE)
		//  if found == idTypeS8 {
		//  	continue
		//  }
		tfS := tf
		//tfS.Type = strings.ToUpper(tfS.Type) // Lower case and upper case Type are not distinguished.

		// In ilu id could point to a different tf. So we need to check that and invalidate id in that case.
		// - That typically happens after tf was changed in source but the id not.
		// - Also the source file with id:tf could be added from a different project and refresh could not add it to ilu because id is used differently.
		// Without this check double used IDs are silently loose one of their usages, what is ok, but this way we get a warning.
		if id != 0 {
			if tfL, ok := ilu[id]; ok { // found
				//tfL.Type = strings.ToUpper(tfL.Type)
				if !reflect.DeepEqual(tfS, tfL) { // Lower case and upper case Type are not distinguished.
					fmt.Fprintln(w, "Id", id, "already used differently, ignoring it.") // todo: patID
					id = -id                                                            // mark as invalid
				}
			}
		}
		if id > 0 {
			li.Line = line
			lim[id] = li
			ilu[id] = tf
			addID(tfS, id, flu)
		}
	}
}

type idType int

const (
	idTypeS8 = 0
	idTypeS4 = 3
	idTypeS2 = 2
	idTypeS0 = 1
)

// updateIDsUniqOrShared parses text for new or invalid *Trices* 'tf' and gives them the legacy id if 'tf' is already in ilu & flu.
// An invalid trice is a trice without Id(n) or with Id(0) or which changed somehow. Examples: 'TRICE( Id(12) ,"foo");' was changed to 'TRICE0( Id(12) ,"bar");'
// If 'TRICE( Id(99) ,"bar");' is in ilu & flu, the invalid trice changes to 'TRICE( Id(99) ,"bar");'. Otherwise instead of 99 a so far unused id is taken.
// Or: 'TRICE( Id(12) ,"foo");' was changed to 'TRICE( Id(13) ,"foo");'. Then ilu & flu are extended accordingly, or, if 13 is already used, it is replaced with a new id.
// Otherwise, a new id is generated, text patched and ilu & flu are extended.
// To work correctly, ilu & flu need to be in a refreshed state, means have all id:tf pairs from Srcs tree already inside.
// text is returned afterwards and true if text was changed and *pListModified set true if s.th. was changed.
// *pListModified in result is true if any file was changed.
// flu holds the tf in upper case.
// ilu holds the tf in source code case. If in source code upper and lower case occur, than only one can be in ilu.
// sharedIDs, if true, reuses IDs for identical format strings.
func updateIDsUniqOrShared(w io.Writer, _ /*sharedIDs*/ bool, min, max TriceID, searchMethod string, text string, ilu TriceIDLookUp, flu triceFmtLookUp, pListModified *bool) (string, bool) {
	var fileModified bool
	subs := text[:] // create a copy of text and assign it to subs
	for {
		loc := matchNbTRICE.FindStringIndex(subs) // find the next TRICE location in file
		if nil == loc {
			return text, fileModified // done
		}
		nbTRICE := subs[loc[0]:loc[1]] // full trice expression with Id(n)
		// prepare subs for next loop
		subs = subs[loc[1]:] // A possible Id(0) replacement makes subs not shorter, so next search can start at loc[1].
		// A case like 'TRICE*( Id(                             0                              ), "");' is not expected.

		nbID, id, tf, idTypeResult := triceParse(nbTRICE)
		//if idTypeResult == idTypeS8 {
		//	continue
		//}
		//tf.Type = strings.ToUpper(tf.Type) // Lower case and upper case Type are not distinguished for normal trices in shared IDs mode.

		// In ilu id could point to a different tf. So we need to check that and invalidate id in that case.
		// - That typically happens after tf was changed in source but the id not.
		// - Also the source file with id:tf could be added from a different project and refresh could not add it to ilu because id is used differently.
		if id != 0 {
			if tfL, ok := ilu[id]; ok { // found
				//tfL.Type = strings.ToUpper(tfL.Type) // Lower case and upper case Type are not distinguished for normal trices in shared IDs mode.
				if !reflect.DeepEqual(tf, tfL) {
					id = -id // mark as invalid
				}
			}
		}
		if id <= 0 { // marked as invalid: id is 0 or inside ilu used differently

			invalID := nbID
			invalTRICE := nbTRICE

			//<<<<<<<<< Temporary merge branch 1
			//			// we need a new one
			//			id = ilu.newID(w, min, max, searchMethod) // a prerequisite is an in a previous step refreshed lu
			//			*pListModified = true
			//			// patch the id into text
			//			nID := fmt.Sprintf("Id(%5d)", id)
			//=========
			//if id, found := flu[tf]; sharedIDs && found { // yes, we can use it in shared IDs mode
			//	msg.FatalInfoOnTrue(id == 0, "no id 0 allowed in map")
			//} else
			//{ // no, we need a new one
			id = ilu.newID(w, min, max, searchMethod) // a prerequisite is an in a previous step refreshed lu
			*pListModified = true
			//}
			var nID string // patch the id into text
			switch idTypeResult {
			case idTypeS8:
				nID = fmt.Sprintf("iD(%5d)", id) // todo: patID
			case idTypeS4:
				nID = fmt.Sprintf("ID(%5d)", id) // todo: patID
			case idTypeS2:
				nID = fmt.Sprintf("Id(%5d)", id) // todo: patID
			case idTypeS0:
				nID = fmt.Sprintf("id(%5d)", id) // todo: patID
			}
			//>>>>>>>>> Temporary merge branch 2
			if Verbose {
				if nID != invalID {
					fmt.Fprint(w, invalID, " -> ")
				}
				fmt.Fprintln(w, nID)
			}
			nbTRICE := strings.Replace(nbTRICE, invalID, nID, 1)
			text = strings.Replace(text, invalTRICE, nbTRICE, 1)
			fileModified = true
		}
		// update map: That is needed after an invalid trice or if id:tf is valid but not inside ilu & flu yet, for example after manual code changes or forgotten refresh before update.
		ilu[id] = tf
		addID(tf, id, flu)
	}
}

/*
// ScIdClean does removes all trice ID's in source tree.
func ScIdClean(w io.Writer, fSys *afero.Afero, cmd *flag.FlagSet) error {
	// todo: just a copy of ScZeroMulti right now.
	if len(Srcs) == 0 {
		Srcs = append(Srcs, "./") // default value
	}
	for i := range Srcs {
		s := Srcs[i]
		srcZ := s
		if _, err := fSys.Stat(srcZ); err == nil { // path exists
			zeroSourceTreeIds(w, fSys, srcZ, !DryRun)
		} else if os.IsNotExist(err) { // path does *not* exist
			fmt.Fprintln(w, s, " -> ", srcZ, "does not exist!")
		} else {
			fmt.Fprintln(w, s, "Schrodinger: file may or may not exist. See err for details.")
			// Therefore, do *NOT* use !os.IsNotExist(err) to test for file existence
			// https://stackoverflow.com/questions/12518876/how-to-check-if-a-file-exists-in-go
		}
	}
	return nil
}

//  // ScZeroMulti does replace all ID's in source tree with 0
//  func ScZeroMulti(w io.Writer, fSys *afero.Afero, cmd *flag.FlagSet) error {
//  	if len(Srcs) == 0 {
//  		Srcs = append(Srcs, "./") // default value
//  	}
//  	for i := range Srcs {
//  		s := Srcs[i]
//  		srcZ := s
//  		if _, err := fSys.Stat(srcZ); err == nil { // path exists
//  			zeroSourceTreeIds(w, fSys, srcZ, !DryRun)
//  		} else if os.IsNotExist(err) { // path does *not* exist
//  			fmt.Fprintln(w, s, " -> ", srcZ, "does not exist!")
//  		} else {
//  			fmt.Fprintln(w, s, "Schrodinger: file may or may not exist. See err for details.")
//  			// Therefore, do *NOT* use !os.IsNotExist(err) to test for file existence
//  			// https://stackoverflow.com/questions/12518876/how-to-check-if-a-file-exists-in-go
//  		}
//  	}
//  	return nil
//  }

// zeroSourceTreeIds is overwriting with 0 all id's from source code tree srcRoot. It does not touch idlist.
func zeroSourceTreeIds(w io.Writer, fSys *afero.Afero, srcRoot string, run bool) {
	//err := filepath.Walk(srcRoot, visitZeroSourceTreeIds(w, fSys, run))
	err := fSys.Walk(srcRoot, visitZeroSourceTreeIds(w, fSys, run))
	if err != nil {
		panic(err)
	}
}

func visitZeroSourceTreeIds(w io.Writer, fSys *afero.Afero, run bool) filepath.WalkFunc {
	// WalkFunc is the type of the function called for each file or directory
	// visited by Walk. The path argument contains the argument to Walk as a
	// prefix; that is, if Walk is called with "dir", which is a directory
	// containing the file "a", the walk function will be called with argument
	// "dir/a". The info argument is the os.FileInfo for the named path.
	//
	// If there was a problem walking to the file or directory named by path, the
	// incoming error will describe the problem and the function can decide how
	// to handle that error (and Walk will not descend into that directory). In the
	// case of an error, the info argument will be nil. If an error is returned,
	// processing stops. The sole exception is when the function returns the special
	// value SkipDir. If the function returns SkipDir when invoked on a directory,
	// Walk skips the directory's contents entirely. If the function returns SkipDir
	// when invoked on a non-directory file, Walk skips the remaining files in the
	// containing directory.
	return func(path string, fi os.FileInfo, err error) error {
		if fi.IsDir() || !isSourceFile(fi) || err != nil {
			return err // forward any error and do nothing
		}
		if Verbose {
			fmt.Fprintln(w, path)
		}
		read, err := fSys.ReadFile(path)
		if err != nil {
			return err
		}
		s := string(read)
		a, b := 0, len(s)
		subs := s[a:b]
		modified := false

		for {
			var found bool
			found, modified, subs, s = zeroNextID(w, modified, subs, s)
			if !found {
				break
			}
		}

		if modified && run {
			err = fSys.WriteFile(path, []byte(s), 0)
		}
		return err
	}
}

// found flag is true if an ID was zeroed, others are updated input values. if an ID wsa zeroed
// - modified gets true
// - subs gets shorter
// - s is updated
func zeroNextID(w io.Writer, modifiedIn bool, subsIn, in string) (found bool, modifiedOut bool, subsOut string, out string) {
	modifiedOut = modifiedIn
	subsOut = subsIn
	out = in
	loc := matchNbTRICE.FindStringIndex(subsIn)
	if nil == loc {
		return
	}
	nbTRICE := subsIn[loc[0]:loc[1]]
	nbID := matchNbID.FindString(nbTRICE)
	if nbID == "" {
		msg.Info(fmt.Sprintln("No 'Id(n)' found inside " + nbTRICE)) // todo: patID
		return
	}

	zeroID := "Id(0)" // todo: patID
	fmt.Fprintln(w, nbID, " -> ", zeroID)

	zeroTRICE := strings.Replace(nbTRICE, nbID, zeroID, 1)
	out = strings.Replace(out, nbTRICE, zeroTRICE, 1)
	// 2^32 has 9 ciphers and shortest trice has 14 chars: TRICE0(Id(1),"");
	// The replacement of n with 0 makes s shorter, so the next search should start like 10 chars earlier.
	subsOut = subsIn[loc[1]-10:]
	found = true
	modifiedOut = true
	return
}
*/
