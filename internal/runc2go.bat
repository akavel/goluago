@echo off
setlocal
set MAIN=c:\prog\gopath\src\code.google.com\p\rsc\c2go
set SRC=

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

echo go run %SRC% %*
go run %SRC% %*

endlocal
