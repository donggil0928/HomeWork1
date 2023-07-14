@echo off
setlocal
call "%~dp0_SetEnv.bat"
start "" %UE_EXE% -Project="%UPROJECT_PATH%" %*