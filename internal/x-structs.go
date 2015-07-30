// +build ignore

package main

import (
	"fmt"
	"os"
	"regexp"

	"gopkg.in/pipe.v2"
)

var p = regexp.MustCompile(`\b(struct|enum)\s+([A-Za-z_0-9]+)`)

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
			typ := string(m[1])
			name := string(m[2])
			if seen[name] {
				return nil
			}
			seen[name] = true
			return []byte(fmt.Sprintf("typedef %s %[2]s %[2]s;\n", typ, name))
		}),
		pipe.Write(os.Stdout),
	))
	if err != nil {
		panic(err)
	}
}
