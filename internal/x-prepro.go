// +build ignore

package main

import (
	"bytes"
	"fmt"
	"os"
	"regexp"

	"gopkg.in/pipe.v2"
)

func main() {
	err := pipe.Run(pipe.Line(
		pipe.Read(os.Stdin),
		pipe.Filter(func(line []byte) bool {
			return !bytes.HasPrefix(line, []byte("#include "))
		}),
		Replace("->top -=", "->top += -", false),
		// FIXME(akavel): c2go chokes on func argument named L,
		// replacing all occurences with 'nil' - below we workaround
		Replace(`\bL\b`, `_L`, true),
		Replace(`'_L'`, `'L'`, true),
		Replace(`"_L"`, `"L"`, true),
		pipe.Write(os.Stdout),
	))
	if err != nil {
		fmt.Fprintf(os.Stderr, "error: %s", err)
		os.Exit(1)
	}
}

func Replace(from, to string, regex bool) pipe.Pipe {
	if !regex {
		return pipe.Replace(func(line []byte) []byte {
			return bytes.Replace(line, []byte(from), []byte(to), -1)
		})
	} else {
		pattern := regexp.MustCompile(from)
		return pipe.Replace(func(line []byte) []byte {
			return pattern.ReplaceAll(line, []byte(to))
		})
	}
}
