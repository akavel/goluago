
#include "stdio.h"
#include "stdlib.h"
#include "lua.h"
#include "lauxlib.h"

#include "../dumper/dumper.inc"
#include "../dumper/dumperh.inc"

typedef struct BufT {
	void *data;
	size_t size;
} Buf;

Buf
readfile(const char *fname) {
	Buf buf = {NULL, 0};
	void *tmp;
	size_t cap = 0;
	int c;
	FILE *fh;
	
	fh = fopen(fname, "r");
	if (!fh)
		return buf;

	for (;;) {
		c = fgetc(fh);
		if (c==EOF)
			break;
		if (buf.size>=cap) {
			cap += cap ? cap : 1;
			tmp = realloc(buf.data, cap);
			if (!tmp)
				return buf;
			buf.data = tmp;
		}
		((char *)buf.data)[buf.size] = (char)c;
		buf.size++;
	}

	fclose(fh);
	return buf;
}

int
main(int argc, char **argv) {
	Buf buf;
	lua_State *L;
	int err;

	if (argc != 2) {
		fprintf(stderr, "USAGE: dbgdump FILE.lua\n");
		return 1;
	}

	buf = readfile(argv[1]);
	if (!buf.data) {
		fprintf(stderr, "readfile error\n");
		return 1;
	}

	L = dumperh_lua_prep();

	err = luaL_loadbuffer(L, buf.data, buf.size, "from loadbuffer");
	if (err != 0) {
		fprintf(stderr, "luaL_loadbuffer error: CODE=%d: %s: %s\n", err,
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
