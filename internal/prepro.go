// +build ignore

package main

import (
	"bytes"
	"fmt"
	"os"

	"gopkg.in/pipe.v2"
)

func main() {
	err := pipe.Run(pipe.Line(
		pipe.Read(os.Stdin),
		pipe.Filter(func(line []byte) bool {
			return !bytes.HasPrefix(line, []byte("#include <"))
		}),
		pipe.Replace(func(line []byte) []byte {
			return bytes.Replace(line, []byte("->top -="), []byte("->top += -"), -1)
		}),
		pipe.Write(os.Stdout),
	))
	if err != nil {
		fmt.Fprintf(os.Stderr, "error: %s", err)
		os.Exit(1)
	}
}
