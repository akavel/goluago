package main

import (
	"os"
	"fmt"
	lua "hg.akavel.com/go-lua/internal"
	"io/ioutil"
	"runtime/debug"
)

func main() {
	defer func() {
		if x := recover(); x != nil {
			fmt.Printf("PANIC: %v\n", x)
			fmt.Printf("panic stacktrace:\n%s", string(debug.Stack()))
		}
	}()

	if len(os.Args)!=2 {
		fmt.Fprintf(os.Stderr, "USAGE: dbgdump FILE.lua\n")
		os.Exit(1)
	}
	
	f, err := ioutil.ReadFile(os.Args[1])
	if err!=nil {
		fmt.Fprintf(os.Stderr, "error: %s\n", err.Error())
		os.Exit(1)
	}
	
	l := lua.OpenDumped()

	res := l.Loadbuffer(f, "@"+os.Args[1])
	if res!=0 {
		fmt.Fprintf(os.Stderr, "lua.Loadbuffer: error %d\n", res)
		os.Exit(1)
	}

	l.Call(0, 0)
	l.Close()
}

/*
int
main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "USAGE: dbgdump FILE.lua\n");
		return 1;
	}

	dumper_Wrap tmp = {l_alloc, NULL, NULL};
	walloc = tmp;
	lua_State *L = lua_newstate(dumper_alloc, &walloc);

	lua_sethook(L, luahook, LUA_MASKCOUNT, 1);

	int err = luaL_loadfile(L, argv[1]);
	if (err != 0) {
		fprintf(stderr, "luaL_loadfile error: CODE=%d: %s: %s\n", err,
			err==LUA_ERRSYNTAX ? "syntax error" :
			err==LUA_ERRMEM ? "memory allocation error" :
			err==LUA_ERRFILE ? "cannot open/read file" :
			"unknown error code",
			lua_tostring(L, -1)
		);
		return 1;
	}

	err = lua_pcall(L, 0, 0, 0);
	if (err != 0) {
		fprintf(stderr, "lua_pcall error: CODE=%d: %s: %s\n", err,
			err==LUA_ERRRUN ? "runtime error" :
			err==LUA_ERRMEM ? "memory allocation error" :
			err==LUA_ERRERR ? "error while running error handler function" :
			"unknown error code",
			lua_tostring(L, -1)
		);
		lua_pop(L, 1);
	}

	lua_close(L);
	return 0;
}

*/