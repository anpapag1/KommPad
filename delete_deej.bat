@echo off
setlocal

:: Request admin privileges if not already running as admin
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Requesting administrative privileges...
    powershell -Command "Start-Process cmd -ArgumentList '/c %~s0' -Verb RunAs"
    exit /b
)

:: Stop deej.exe if it is running
echo Checking if deej.exe is running...
tasklist /FI "IMAGENAME eq deej.exe" | find /I "deej.exe" >nul
if %errorLevel% equ 0 (
    echo Stopping deej.exe...
    taskkill /F /IM deej.exe >nul
    echo deej.exe stopped successfully.
) else (
    echo deej.exe is not running.
)

:: Define the directory to delete
set "target_dir=C:\Program Files\deej"

:: Check if the directory exists
if exist "%target_dir%" (
    echo Deleting directory "%target_dir%"...
    rmdir /s /q "%target_dir%"
    echo Directory deleted successfully.
) else (
    echo Directory "%target_dir%" does not exist.
)

:: Define the startup folder shortcut path
set "startup_shortcut=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\deej.lnk"

:: Check if the shortcut exists in the startup folder and delete it
if exist "%startup_shortcut%" (
    echo Deleting shortcut "%startup_shortcut%"...
    del "%startup_shortcut%"
    echo Shortcut deleted successfully.
) else (
    echo Shortcut "%startup_shortcut%" does not exist.
)

pause