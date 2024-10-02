// Copyright 2020 Thomas.Hoehenleitner [at] seerose.net
// Use of this source code is governed by a license that can be found in the LICENSE file.

package main

import (
	"bytes"
	"io"
	"testing"

	"github.com/rokath/trice/internal/args"
	"github.com/spf13/afero"
	"github.com/tj/assert"
)

func TestUpdate0(t *testing.T) { // Anti-Virus issue

	fSys := &afero.Afero{Fs: afero.NewMemMapFs()}
	defer setupTest(t, fSys)()

	//fSys := &afero.Afero{Fs: afero.NewMemMapFs()}

	// create src file
	sFn := "file.c"
	src := ` // this is line 1
	break; case __LINE__: TRICE8_1( id(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( id(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( Id(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( Id(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( ID(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( ID(0), "msg:value=%d\n", -1  ); // legacy default with times stamp
`
	assert.Nil(t, fSys.WriteFile(sFn, []byte(src), 0777))

	// create empty til.json
	jFn := "til.json"
	JSONFile := ``
	assert.Nil(t, fSys.WriteFile(jFn, []byte(JSONFile), 0777))

	// action
	var b bytes.Buffer
	assert.Nil(t, args.Handler(io.Writer(&b), fSys, []string{"trice", "u", "-src", ".", "-v", "-IDMin", "1000", "-IDMax", "2000", "-IDMethod", "upward"}))

	// check modified src file
	expSrc := ` // this is line 1
	break; case __LINE__: TRICE8_1( id( 1000), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( id( 1001), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( Id( 1002), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( Id( 1003), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( ID( 1004), "msg:value=%d\n", -1  ); // legacy default with times stamp
	break; case __LINE__: TRICE8_1( ID( 1005), "msg:value=%d\n", -1  ); // legacy default with times stamp
`
	actSrc, e := fSys.ReadFile(sFn)
	assert.Nil(t, e)
	assert.Equal(t, expSrc, string(actSrc))

	// check modified til.json file
	expJSON := `{
	"1000": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	},
	"1001": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	},
	"1002": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	},
	"1003": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	},
	"1004": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	},
	"1005": {
		"Type": "TRICE8_1",
		"Strg": "msg:value=%d\\n"
	}
}`
	actJSON, e := fSys.ReadFile(jFn)
	assert.Nil(t, e)
	assert.Equal(t, expJSON, string(actJSON))

	// check console output
	expOut := `Read ID List file til.json with 0 items.
dir= .
List= til.json
file.c
IDMin= 1000 IDMax= 2000 IDMethod= upward
id(0) -> id( 1000)
IDMin= 1000 IDMax= 2000 IDMethod= upward
id(0) -> id( 1001)
IDMin= 1000 IDMax= 2000 IDMethod= upward
Id(0) -> Id( 1002)
IDMin= 1000 IDMax= 2000 IDMethod= upward
Id(0) -> Id( 1003)
IDMin= 1000 IDMax= 2000 IDMethod= upward
ID(0) -> ID( 1004)
IDMin= 1000 IDMax= 2000 IDMethod= upward
ID(0) -> ID( 1005)
Changed:  file.c
6 ID's in List til.json listModified= true
`
	actOut := b.String()
	assert.Equal(t, expOut, actOut)

	// check generated li.json file
	expLI := `{
	"1000": {
		"File": "file.c",
		"Line": 2
	},
	"1001": {
		"File": "file.c",
		"Line": 3
	},
	"1002": {
		"File": "file.c",
		"Line": 4
	},
	"1003": {
		"File": "file.c",
		"Line": 5
	},
	"1004": {
		"File": "file.c",
		"Line": 6
	},
	"1005": {
		"File": "file.c",
		"Line": 7
	}
}`
	actLI, e := fSys.ReadFile("li.json")
	assert.Nil(t, e)
	assert.Equal(t, expLI, string(actLI))

}
