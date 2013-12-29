@if "%1"=="" goto :eof
lua wrap-test.lua lua5.1-tests\%1.lua | gofmt > internal\lua%1_test.go