// Copyright 2020 Thomas.Hoehenleitner [at] seerose.net
// Use of this source code is governed by a license that can be found in the LICENSE file.

package id_test

import (
	"bytes"
	"io"
	"testing"

	"github.com/rokath/trice/internal/args"
	"github.com/rokath/trice/internal/id"
	"github.com/spf13/afero"
	"github.com/tj/assert"
)

func TestClean(t *testing.T) {
	fSys := &afero.Afero{Fs: afero.NewMemMapFs()}

	// create src file
	sFn := t.Name() + "file.c"
	src := `break; case __LINE__: trice( iD(999), "msg:value=%d\n", -1  );`

	assert.Nil(t, fSys.WriteFile(sFn, []byte(src), 0777))

	// create empty til.json
	jFn := t.Name() + "til.json"
	JSONFile := ``
	assert.Nil(t, fSys.WriteFile(jFn, []byte(JSONFile), 0777))

	// create empty li.json
	liFn := t.Name() + "li.json"
	assert.Nil(t, fSys.WriteFile(liFn, []byte(``), 0777))

	// we need to make sure, idSrcs contains exactly the local test folder to not to interfere with other tests
	var x id.ArrayFlag
	x.Set("./")
	id.Srcs = x

	// action
	var b bytes.Buffer
	assert.Nil(t, args.Handler(io.Writer(&b), fSys, []string{"trice", "clean" /*"-src", "./",*/, "-til", jFn, "-li", liFn}))

	// check modified src file
	expSrc := `break; case __LINE__: trice( "msg:value=%d\n", -1  );`

	actSrc, e := fSys.ReadFile(sFn)
	assert.Nil(t, e)

	assert.Equal(t, expSrc, string(actSrc))
}

func TestZero(t *testing.T) {
	fSys := &afero.Afero{Fs: afero.NewMemMapFs()}

	// create src file
	sFn := t.Name() + "file.c"
	src := `break; case __LINE__: trice( iD(999), "msg:value=%d\n", -1  );`

	assert.Nil(t, fSys.WriteFile(sFn, []byte(src), 0777))

	// create empty til.json
	jFn := t.Name() + "til.json"
	JSONFile := ``
	assert.Nil(t, fSys.WriteFile(jFn, []byte(JSONFile), 0777))

	// create empty li.json
	liFn := t.Name() + "li.json"
	assert.Nil(t, fSys.WriteFile(liFn, []byte(``), 0777))

	// we need to make sure, idSrcs contains exactly the local test folder to not to interfere with other tests
	var x id.ArrayFlag
	x.Set("./")
	id.Srcs = x

	// action
	var b bytes.Buffer
	assert.Nil(t, args.Handler(io.Writer(&b), fSys, []string{"trice", "zero" /*"-src", "./",*/, "-til", jFn, "-li", liFn}))

	// check modified src file
	expSrc := `break; case __LINE__: trice( iD(0), "msg:value=%d\n", -1  );`

	actSrc, e := fSys.ReadFile(sFn)
	assert.Nil(t, e)

	assert.Equal(t, expSrc, string(actSrc))
}
