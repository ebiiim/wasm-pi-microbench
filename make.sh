#!/bin/sh
GOOS=js GOARCH=wasm go build -o mcpi.wasm mcpi.go
