// +build ignore

package main

import (
	"os"
	"regexp"

	"gopkg.in/pipe.v2"
)

func main() {
	p := regexp.MustCompile(`\bstruct\s+([A-Za-z_0-9]+)`)
	seen := map[string]bool{}
	// extract all "struct foobar", change to typedefs
	err := pipe.Run(pipe.Line(
		pipe.Read(os.Stdin),
		pipe.Replace(func(line []byte) []byte {
			m := p.FindSubmatch(line)
			if m == nil {
				return nil
			}
			s := string(m[1])
			if seen[s] {
				return nil
			}
			seen[s] = true
			return []byte("typedef struct " + s + " " + s + ";\n")
		}),
		pipe.Write(os.Stdout),
	))
	if err != nil {
		panic(err)
	}
}
