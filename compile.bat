SET EMSDKPATH=C:\bin\emsdk
CALL %EMSDKPATH%\emsdk_env.bat
em++ fact.cpp -O3 -s WASM=1 -s NO_EXIT_RUNTIME=1  -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']" -Wc++11-extensions -o fact.html
