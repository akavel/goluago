::@echo off
setlocal
set LUASRC=
set PREPRO=c:\mingw-tdm64\bin\cpp.exe
::FIXME - must make this cross-platform:
set RUNTIME=windows_amd64
set C2GO=%gopath%\bin\c2go

:: make sure we have c2go installed
go get -v github.com/akavel/c2go

:: collect main headers of Lua
rmdir /q/s tmph  2> nul
mkdir tmph
for %%f in (*.h) do (
  findstr /v /c:"#include <" %%f  > tmph\%%f
)

:: patch some headers
echo.                      > tmph\gostdc.h
type *.h l*.c | go run x-structs.go | findstr /v /c:"struct va_list" | findstr /v /c:"struct time_t" >> tmph\gostdc.h
echo #include "fix2go.h"  >> tmph\gostdc.h
echo #undef luaL_argcheck >> tmph\lauxlib.h
echo #define luaL_argcheck(a,b,c,d) mylua_argcheck(a,((b)!=0),c,d) >> tmph\lauxlib.h
echo #undef luaL_setn     >> tmph\lauxlib.h
echo #define luaL_setn(a,b,c) NOP() >> tmph\lauxlib.h
echo #undef luaL_getmetatable >> tmph\lauxlib.h
echo #define luaL_getmetatable(L,n) lua_getfield(L,LUA_REGISTRYINDEX,(n)) >> tmph\lauxlib.h

:: merge all headers of Lua
echo #include "gostdc.h" > tmph\bigh0.h
for %%f in (l*.c) do (
  findstr /c:"#include "" %%f
) >> tmph\bigh0.h
cd tmph
:: -C  keep comments
:: -P  don't generate linemarkers
%PREPRO% -C -P -D LUA_CORE < bigh0.h | go run ../x-prepro.go > bigh.h
cd ..

:: expand macros in main sources of Lua
rmdir /q/s tmpc  2> nul
mkdir tmpc
:: FIXME(akavel): for now, working on one file only; increase to all when ready
::for %%f in (l*.c) do call :expandMacros %%f
for %%f in (lauxlib.c) do call :expandMacros %%f

rmdir /q/s tmpgo  2> nul
%C2GO% -c=x-c2go.cfg -dst=tmpgo -I=%CD%/tmpc %LUASRC% 2> x-errors2go.txt

endlocal
goto :eof

:expandMacros luamodule.c
  echo #include "../tmph/bigh.h" > tmpc\%1
  type %1 | go run x-prepro.go | %PREPRO% -C -P -D LUA_CORE -imacros tmph/bigh0.h >> tmpc\%1
  call set LUASRC=%%LUASRC%% tmpc/%1
goto :eof



echo #include "gostdc.h" > tmpc\amalgm0.c
for %%f in (l*.c) do (
  go run x-prepro.go < %%f >> tmpc\amalgm0.c
  call set LUASRC=%%LUASRC%% tmpc/%%f
)
cd tmpc
%PREPRO% -C < amalgm0.c > amalgm.c
cd ..

::%C2GO% -c x-c2go.cfg -dst tmpgo -I=%CD%/tmph %LUASRC% 2> x-errors2go.txt
%C2GO% -c x-c2go.cfg -dst tmpgo tmpc\amalgm.c 2> x-errors2go.txt

endlocal
