
static void *
dumperh_l_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
	(void)ud;
	(void)osize;
	if (nsize == 0) {
		free(ptr);
		return NULL;
	}
	return realloc(ptr, nsize);
}

static void
dumperh_prints(const char *s) {
	fprintf(stderr, "%s", s);
}

static dumper_Wrap dumperh_walloc;

static void
dumperh_luahook(lua_State *L, lua_Debug *dbg) {
	dumperh_prints("\n====== HOOK DUMP ======\n");
	dumper_dump(&dumperh_walloc);
}

static lua_State *
dumperh_lua_prep(void) {
	dumper_Wrap tmp = {dumperh_l_alloc, NULL, dumperh_prints, NULL};
	dumperh_walloc = tmp;
	lua_State *L = lua_newstate(dumper_alloc, &dumperh_walloc);

	lua_sethook(L, dumperh_luahook, LUA_MASKCOUNT, 1);
	return L;
}

