// Copyright 2020 Thomas.Hoehenleitner [at] seerose.net
// Use of this source code is governed by a license that can be found in the LICENSE file.

// Package args implemets the commandline interface and calls the appropriate commands.
package args

import (
	"errors"
	"flag"
	"fmt"
	"os"
	"strings"

	"github.com/rokath/trice/internal/com"
	"github.com/rokath/trice/internal/emitter"
	"github.com/rokath/trice/internal/id"
	"github.com/rokath/trice/internal/link"
	"github.com/rokath/trice/internal/receiver"
	"github.com/rokath/trice/internal/translator"
	"github.com/rokath/trice/pkg/cage"
)

// Handler is called in main, evaluates args and calls the appropriate functions.
// It returns for program exit.
func Handler(args []string) error {

	if "" == Date { // goreleaser will set Date, otherwise use file info
		fi, err := os.Stat(os.Args[0])
		if nil == err { // On running main tests fileinfo is invalid, so do not use in that case.
			Date = fi.ModTime().String()
		}
	}
	cage.DefaultLogfileName = "2006-01-02_1504-05_trice.log"

	// Verify that a subcommand has been provided: os.Arg[0] is the main command, os.Arg[1] will be the subcommand.
	if len(os.Args) < 2 {
		msg := "no args, try: 'trice help'"
		fmt.Println(msg)
		return errors.New(msg)
	}

	// Switch on the subcommand. Parse the flags for appropriate FlagSet.
	// FlagSet.Parse() requires a set of arguments to parse as input.
	// os.Args[2:] will be all arguments starting after the subcommand at os.Args[1]
	subCmd := args[1]
	subArgs := args[2:]
	switch subCmd { // Check which subcommand is invoked.
	case "h", "help":
		fsScHelp.Parse(subArgs)
		distributeArgs()
		return scHelp(fsScLog, fsScZero, fsScVersion, fsScSv, fsScSdSv)
	case "s", "sc", "scan":
		fsScScan.Parse(subArgs)
		distributeArgs()
		_, err := com.GetSerialPorts()
		return err
	case "v", "ver", "version":
		fsScVersion.Parse(subArgs)
		distributeArgs()
		return scVersion()
	case "u", "update":
		fsScUpdate.Parse(subArgs)
		distributeArgs()
		fnJSON = id.ConditionalFilePath(fnJSON)
		return id.ScUpdate(fnJSON)
	case "zeroSourceTreeIds":
		fsScZero.Parse(subArgs)
		distributeArgs()
		return id.ScZero(*pSrcZ, fsScZero)
	case "l", "log":
		fsScLog.Parse(subArgs)
		distributeArgs()
		return receiving()
	case "ds", "displayServer":
		fsScSv.Parse(subArgs)
		distributeArgs()
		return emitter.ScDisplayServer()
	case "sd", "sdds", "sdrds", "shutdownRemoteDisplayServer":
		fsScSdSv.Parse(subArgs)
		distributeArgs()
		return emitter.ScShutdownRemoteDisplayServer(1)
	default:
		fmt.Println("try: 'trice help|h'")
		return nil
	}
}

// scHelp is subcommand help. It prits usage to stdout.
func scHelp(
	l *flag.FlagSet,
	z *flag.FlagSet,
	v *flag.FlagSet,
	sv *flag.FlagSet,
	scSdSv *flag.FlagSet,
) error {
	if Verbose {
		fmt.Printf("\n*** https://github.com/rokath/trice ***\n\n")
		fmt.Printf("If a non-multi parameter is used more than one times the last value wins.\n")
	}
	cage.Enable()
	defer cage.Disable()

	fmt.Println("syntax: 'trice subcommand' [params]")
	fmt.Println("subcommand 'help', 'h' for command line usage")
	fsScHelp.SetOutput(os.Stdout)
	fsScHelp.PrintDefaults()
	fmt.Println("subcommand 'u', 'upd', 'update' for updating ID list and source files")
	fsScUpdate.SetOutput(os.Stdout)
	fsScUpdate.PrintDefaults()
	fmt.Println("subcommand 'l', 'log' for displaying trice logs coming from source")
	l.SetOutput(os.Stdout)
	l.PrintDefaults()
	fmt.Println("subcommand 'zeroSourceTreeIds' for setting all TRICE IDs to 0 in source tree, avoid using this subcommand normally")
	z.SetOutput(os.Stdout)
	z.PrintDefaults()
	fmt.Println("subcommand 'v', 'ver', 'version' for displaying version information")
	v.SetOutput(os.Stdout)
	v.PrintDefaults()
	fmt.Println("subcommand 'ds', 'displayServer' starts a display server, use in a separate console, on Windows use wt or a linux shell like git-bash to avoid color issues, several instances of 'trice l -ds' will send output there")
	sv.SetOutput(os.Stdout)
	sv.PrintDefaults()
	fmt.Println("subcommand 'sd', 'shutdownServer' ends display server at IPA:IPP, works also on a remote mashine")
	scSdSv.SetOutput(os.Stdout)
	scSdSv.PrintDefaults()
	fmt.Println("examples:")
	fmt.Println("    'trice update -src ../A -src ../../B' parses ../A and ../../B with all subdirectories for TRICE IDs to update and adjusts til.json")
	fmt.Println("    'trice l -s COM15 -baud 38400 -d wrap display wrap data format trice log messages from COM15")
	fmt.Println("    'trice l display bare data format trice log messages from default source")
	fmt.Println("    'trice zeroSourceTreeIds -dir ../A' sets all TRICE IDs to 0 in ./A")
	fmt.Println("    'trice v -v' shows verbose version information")
	return nil
}

// scVersion is subcommand 'version'
func scVersion() error {
	cage.Enable()
	defer cage.Disable()
	if Verbose {
		fmt.Println("https://github.com/rokath/trice")
	}
	if "" != Version {
		fmt.Printf("version=%v, commit=%v, built at %v\n", Version, Commit, Date)
	} else {
		fmt.Printf("version=devel, built %s\n", Date)
	}
	return nil
}

// setDefaultArgs sets args being literally "default" to their mode specific default value.
func setDefaultArgs() {
	if "default" == Encoding {
		switch Port {
		case "JLINK", "STLINK":
			Encoding = "bare"
		default:
			if strings.HasPrefix(Port, "COM") {
				Encoding = "bare"
			}
		}
	}
}

// distributeArgs is distibuting values used in several packages.
// It must not be called before the appropriate arg parsing.
func distributeArgs() {
	setDefaultArgs()
	id.Verbose = Verbose
	emitter.Verbose = Verbose
	link.Verbose = Verbose
	cage.Verbose = Verbose
	receiver.Verbose = Verbose
	translator.Verbose = Verbose
	link.Port = Port
}
