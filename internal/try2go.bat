::@echo off
setlocal
set LUASRC=
set PREPRO=c:\mingw-tdm64\bin\cpp.exe
::FIXME - must make this cross-platform:
set RUNTIME=windows_amd64

:: collect main headers of Lua
rmdir /q/s tmpc  2> nul
mkdir tmpc
for %%f in (*.h) do (
  rem findstr /v /c:"#include <" %%f | powershell -Command "$input | %% {$_ -replace \"lua_TValue\",\"TValue\"}" >> tmpc\%%f
  findstr /v /c:"#include <" %%f  >> tmpc\%%f
  rem call set LUASRC=%%LUASRC%% tmpc/%%f
)

:: patch some headers
echo #include "fix2go.h" >tmpc\gostdc.h
echo #undef luaL_argcheck >> tmpc\lauxlib.h
echo #define luaL_argcheck(a,b,c,d) mylua_argcheck(a,((b)!=0),c,d) >> tmpc\lauxlib.h
echo #undef luaL_setn >> tmpc\lauxlib.h
echo #define luaL_setn(a,b,c) NOP() >> tmpc\lauxlib.h

:: collect main sources of Lua
echo #include "gostdc.h" > tmpc\amalgm0.c
for %%f in (l*.c) do (
  go run prepro.go < %%f >> tmpc\amalgm0.c
  call set LUASRC=%%LUASRC%% tmpc/%%f
)
cd tmpc
%PREPRO% -C < amalgm0.c > amalgm.c
cd ..

::call runc2go -f fixup.txt -o tmpgo -I=%CD%/tmph %LUASRC% 2> errors2go.txt
call runc2go -f fixup.txt -o tmpgo tmpc\amalgm.c 2> errors2go.txt

endlocal
