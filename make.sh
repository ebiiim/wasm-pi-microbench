#!/bin/sh
GOOS=js GOARCH=wasm go build -o mcpi-go.wasm src/mcpi.go
