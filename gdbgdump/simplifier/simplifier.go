package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Buf []byte

func Decode(s string) Buf {
	b := Buf{}
	b.DecodeMore(s)
	return b
}

func (b *Buf) DecodeMore(s string) {
	n := 0
	for _, c := range []byte(s) {
		if c == '*' {
			c = '0'
		}
		switch {
		case c >= '0' && c <= '9':
			c -= '0'
		case c >= 'a' && c <= 'f':
			c = c - 'a' + 10
		default:
			continue
		}
		switch {
		case n%2 == 0:
			*b = append(*b, c<<4)
		default:
			(*b)[len(*b)-1] += c
		}
		n++
	}
}

func (b Buf) ToInt64() int64 {
	if len(b) != 8 {
		panic(fmt.Sprintf("length is %d", len(b)))
	}
	return int64(b[0])<<(8*0) +
		int64(b[1])<<(8*1) +
		int64(b[2])<<(8*2) +
		int64(b[3])<<(8*3) +
		int64(b[4])<<(8*4) +
		int64(b[5])<<(8*5) +
		int64(b[6])<<(8*6) +
		int64(b[7])<<(8*7)
}

type Node struct {
	Begin, End int64
}

type HexFmt struct {
	Off int64
}

func (h *HexFmt) Byte(b byte) {
	buf := []byte(fmt.Sprintf("%02x", b))
	h.Fmt(buf[0], buf[1])
}
func (h *HexFmt) Fmt(c1, c2 byte) {
	if h.Off%16 == 0 {
		if h.Off > 0 {
			fmt.Println()
		}
		fmt.Printf("  0x%08x: ", h.Off)
	}
	if h.Off%4 == 0 {
		fmt.Printf(" ")
	}
	fmt.Printf("%c%c", c1, c2)
	h.Off++
}

func main() {
	nodes := []*Node{}
	var buf Buf

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		line := scanner.Text()
		switch {
		case strings.HasPrefix(line, "NODE "):
			if len(buf) > 0 {
				hex := HexFmt{}
				// try to find addresses in memory chunks
			addresses:
				for i := 0; i < len(buf)-8; i++ {
					value := Buf(buf[i : i+8]).ToInt64()
					for j, node := range nodes {
						if node == nil || value < node.Begin || value >= node.End {
							continue
						}
						// FIXME: print some marker
						value -= node.Begin
						hex.Fmt('#', '#')
						hex.Byte(byte((j + 1) >> 8))
						hex.Byte(byte(j + 1))
						hex.Fmt('#', '#')
						hex.Byte(byte(value >> 24))
						hex.Byte(byte(value >> 16))
						hex.Byte(byte(value >> 8))
						hex.Byte(byte(value))
						continue addresses
					}
					hex.Byte(buf[i])
				}
				for i := len(buf) - 8; i < len(buf); i++ {
					hex.Byte(buf[i])
				}
				buf = nil
				fmt.Println()
			}
			//fmt.Println(line)
			parts := strings.Split(line, " ")
			fmt.Println(parts[0], parts[1], parts[2], parts[6], parts[7], parts[8])

			n := Decode(parts[1] + parts[2]).ToInt64()
			addr := Decode(parts[4] + parts[5]).ToInt64()
			size := Decode(parts[7] + parts[8]).ToInt64()
			for int64(len(nodes)) < n-1 {
				nodes = append(nodes, nil)
			}
			nodes = append(nodes, &Node{Begin: addr, End: addr + size})
			if int64(len(nodes)) != n {
				panic(fmt.Sprint(len(nodes), "!=", n))
			}
		case strings.HasPrefix(line, "------ DUMP ID"):
			nodes = nodes[:0]
			fmt.Println("\n" + line)
		case strings.HasPrefix(line, "  0x"):
			buf.DecodeMore(line[15:])
		default:
			fmt.Println(line)
			continue
		}
	}
}
