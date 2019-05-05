#!/bin/sh

# Go
GOOS=js GOARCH=wasm go build -o mcpi-go.wasm src/mcpi.go

# C/C++
emcc -O3 -o mcpi-cpp.js -s WASM=1 src/mcpi.cpp 
sed -e 's/var shouldRunNow=true;/var shouldRunNow=false;/' mcpi-cpp.js > mcpi-cpp.js.tmp
cp mcpi-cpp.js.tmp mcpi-cpp.js
