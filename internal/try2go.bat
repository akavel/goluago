::@echo off
setlocal
set MAIN=c:\prog\gopath\src\code.google.com\p\rsc\c2go
set SRC=
set LUASRC=
set PREPRO=c:\mingw-tdm64\bin\cpp.exe
::FIXME - must make this cross-platform:
set RUNTIME=windows_amd64

:: install c2go-related libs
go install -v code.google.com/p/rsc/cc
go install -v code.google.com/p/rsc/c2go

:: collect main sources of c2go
rmdir /q/s tmp2go  2> nul
mkdir tmp2go
copy %MAIN%\*.* tmp2go\  > nul
del tmp2go\printer.go
for %%f in (tmp2go\*.go) do (
  call set SRC=%%SRC%% %%f
)
::echo %SRC%

:: collect main headers of Lua
rmdir /q/s tmpc  2> nul
mkdir tmpc
for %%f in (*.h) do (
  findstr /v /c:"#include <" %%f >> tmpc\%%f
  rem call set LUASRC=%%LUASRC%% tmpc/%%f
)

:: patch some headers
echo #include "fix2go.h" >tmpc\gostdc.h
echo #undef luaL_argcheck >> tmpc\lauxlib.h
echo #define luaL_argcheck(a,b,c,d) mylua_argcheck(a,b,c,d) >> tmpc\lauxlib.h
echo #undef luaL_setn >> tmpc\lauxlib.h
echo #define luaL_setn(a,b,c) NOP() >> tmpc\lauxlib.h

:: collect main sources of Lua
for %%f in (l*.c) do (
  cd tmpc
  (echo #include "gostdc.h" && findstr /v /c:"#include <" ..\%%f) | %PREPRO% >> %%f
  cd ..
  call set LUASRC=%%LUASRC%% tmpc/%%f
)

:::: collect all needed headers
::rmdir /q/s tmph  2> nul
::mkdir tmph
::::for %%f in (..\..\gostdc\*.h) do (
::::	echo %%~nxf
::::)
::::copy ..\..\gostdc\*.h tmph\  > nul
::::copy %GOROOT%\pkg\%RUNTIME%\runtime.h  tmph\  > nul

go run %SRC% -f fixup.txt -o tmpgo -I=%CD%/tmph %LUASRC% 2> errors2go.txt

endlocal
