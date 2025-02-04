@echo off
setlocal enabledelayedexpansion

:: Define installation directory
set "install_dir=C:\Program Files\deej"

:: Define URLs for the latest release
set "deej_url=https://github.com/omriharel/deej/releases/latest/download/deej.exe"
set "config_url=https://github.com/omriharel/deej/releases/latest/download/config.yaml"

:: Define startup folder path
set "startup_folder=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
set "shortcut=%startup_folder%\deej.lnk"

:: Request admin privileges if not already running as admin
net session >nul 2>&1
if %errorLevel% neq 0 (
    echo Requesting administrative privileges...
    powershell -Command "Start-Process cmd -ArgumentList '/c %~s0' -Verb RunAs"
    exit /b
)

:: Create installation directory
if not exist "%install_dir%" (
    echo Creating installation directory...
    mkdir "%install_dir%"
)

:: Download deej.exe
echo Downloading deej.exe...
curl -L "%deej_url%" -o "%install_dir%\deej.exe"

:: Download config.yaml
echo Downloading config.yaml...
curl -L "%config_url%" -o "%install_dir%\config.yaml"

:: Grant full permissions to the install directory (required for writing config updates)
icacls "%install_dir%" /grant Everyone:F /T /C /Q

:: Create a shortcut in the startup folder
echo Creating shortcut in Startup folder...
echo Set oWS = WScript.CreateObject("WScript.Shell") > "%TEMP%\create_shortcut.vbs"
echo Set oLink = oWS.CreateShortcut("%shortcut%") >> "%TEMP%\create_shortcut.vbs"
echo oLink.TargetPath = "%install_dir%\deej.exe" >> "%TEMP%\create_shortcut.vbs"
echo oLink.Save >> "%TEMP%\create_shortcut.vbs"

:: Run the VBScript to create the shortcut
cscript //nologo "%TEMP%\create_shortcut.vbs"

:: Clean up VBScript
del "%TEMP%\create_shortcut.vbs"

echo Installation complete! Deej has been installed in "%install_dir%" and will run on startup.
pause
