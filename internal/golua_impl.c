
#include "lua.h"

#include "lauxlib.h"
#include "lualib.h"

#include "goctypes.h"

/*from: ldo.h:*/
/* type of protected functions, to be ran by `runprotected' */
typedef void (*Pfunc) (lua_State *L, void *ud);

void
_luai_try(lua_State *L, Pfunc f, void *ud) {
    void ·go_try(uintptr, uintptr, uintptr);
    ·go_try((uintptr)L, (uintptr)f, (uintptr)ud);
}

void
·golua_call(lua_State *L, Pfunc f, void *ud) {
    (*f)(L, ud);
}

void
_luai_throw(lua_State *L) {
    void ·go_throw(uintptr);
    ·go_throw((uintptr)L);
}
