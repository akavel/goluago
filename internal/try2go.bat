::@echo off
setlocal
set LUASRC=
set PREPRO=c:\mingw-tdm64\bin\cpp.exe
::FIXME - must make this cross-platform:
set RUNTIME=windows_amd64
set C2GO=%gopath%\bin\c2go

:: make sure we have c2go installed
:: TODO(akavel): fork to keep a stable, controlled version
go get -v rsc.io/c2go

:: collect main headers of Lua
rmdir /q/s tmph  2> nul
mkdir tmph
for %%f in (*.h) do (
  findstr /v /c:"#include <" %%f  > tmph\%%f
)

:: patch some headers
echo.                      > tmph\gostdc.h
type *.h l*.c | go run xstructs.go | findstr /v /c:"struct va_list" | findstr /v /c:"struct time_t" >> tmph\gostdc.h
echo #include "fix2go.h"  >> tmph\gostdc.h
echo #undef luaL_argcheck >> tmph\lauxlib.h
echo #define luaL_argcheck(a,b,c,d) mylua_argcheck(a,((b)!=0),c,d) >> tmph\lauxlib.h
echo #undef luaL_setn     >> tmph\lauxlib.h
echo #define luaL_setn(a,b,c) NOP() >> tmph\lauxlib.h

:: merge all headers of Lua
echo #include "gostdc.h" > tmph\bigh0.h
for %%f in (l*.c) do (
  findstr /c:"#include "" %%f  
) >> tmph\bigh0.h
cd tmph
:: -C  keep comments
:: -P  don't generate linemarkers
%PREPRO% -C -P -D LUA_CORE < bigh0.h > bigh.h
cd ..

:: expand macros in main sources of Lua
rmdir /q/s tmpc  2> nul
mkdir tmpc
for %%f in (l*.c) do (
  echo #include "../tmph/bigh.h" > tmpc\%%f
  type %%f | go run prepro.go | %PREPRO% -C -P -D LUA_CORE -imacros tmph/bigh0.h >> tmpc\%%f
  call set LUASRC=%%LUASRC%% tmpc/%%f
)

rmdir /q/s tmpgo  2> nul
%C2GO% -c=c2go.cfg -dst=tmpgo -I=%CD%/tmpc %LUASRC% 2> errors2go.txt

endlocal
goto :eof



echo #include "gostdc.h" > tmpc\amalgm0.c
for %%f in (l*.c) do (
  go run prepro.go < %%f >> tmpc\amalgm0.c
  call set LUASRC=%%LUASRC%% tmpc/%%f
)
cd tmpc
%PREPRO% -C < amalgm0.c > amalgm.c
cd ..

::%C2GO% -c c2go.cfg -dst tmpgo -I=%CD%/tmph %LUASRC% 2> errors2go.txt
%C2GO% -c c2go.cfg -dst tmpgo tmpc\amalgm.c 2> errors2go.txt

endlocal
