// +build ignore

package main

import (
	"os"
	"regexp"

	"gopkg.in/pipe.v2"
)

var p = regexp.MustCompile(`\bstruct\s+([A-Za-z_0-9]+)`)

func main() {
	seen := map[string]bool{}
	err := pipe.Run(pipe.Line(
		pipe.Read(os.Stdin),
		// extract all "struct foobar", change to typedefs
		pipe.Replace(func(line []byte) []byte {
			m := p.FindSubmatch(line)
			if m == nil {
				return nil
			}
			name := string(m[1])
			if seen[name] {
				return nil
			}
			seen[name] = true
			return []byte("typedef struct " + name + " " + name + ";\n")
		}),
		pipe.Write(os.Stdout),
	))
	if err != nil {
		panic(err)
	}
}
