#!/usr/bin/env bash

cp ./testdata/triceCheck.c.txt ./testdata/triceCheck.c
cp ./testdata/triceCheck.c.txt ../examples/exampleData/triceCheck.c

# create til.json && li.json if not existing
touch ./testdata/til.json ./testdata/li.json

#  insert IDs into source code
trice insert -i ./testdata/til.json -li ./testdata/li.json -liPathIsRelative -IDMin 1000 -IDMax 7999

# The file cgoPackage.go is the same in all cgo test packages, but must be inside the folders.
# os agnostic links would be better.
CGOTESTDIRS="
staticBuffer_cobs
staticBuffer_tcobs
staticBuffer_nopf
staticBuffer_xtea_nopf
staticBuffer_xtea_cobs
staticBuffer_xtea_tcobs

stackBuffer_tcobs
stackBuffer_cobs
stackBuffer_nopf

ringBuffer_deferred_tcobs
ringBuffer_deferred_cobs
ringBuffer_deferred_xtea_cobs

doubleBuffer_deferred_single_tcobs
doubleBuffer_deferred_multi_tcobs
doubleBuffer_deferred_single_cobs
doubleBuffer_deferred_multi_cobs
doubleBuffer_deferred_multi_xtea_cobs

doubleBuffer_direct_noRouting_nopf
doubleBuffer_twin_direct_noRouting_nopf_deferred_multi_cobs
"
for d in $CGOTESTDIRS
do
cp ./testdata/cgoPackage.go ./$d/generated_cgoPackage.go
done

go clean -cache
