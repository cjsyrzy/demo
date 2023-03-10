@mkdir build
@cd build

cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
@ if errorlevel 1 goto end

cmake --build .
@ if errorlevel 1 goto end

@REM @move .\mps_tool.exe ..\..\MPS_TOOL\mps_tool.exe

:end
@cd ..
@REM clean.bat
@REM @ exit
@REM @pause
