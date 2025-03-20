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
echo Downloading deej.exe from github...
curl -L "%deej_url%" -o "%install_dir%\deej.exe"

:: Download config.yaml
echo Downloading config.yaml from github...
curl -L "%config_url%" -o "%install_dir%\config.yaml"

:: Grant full permissions to the install directory (required for writing config updates)
icacls "%install_dir%" /grant Everyone:F /T /C /Q

:: Create a shortcut in the startup folder
echo Creating shortcut in Startup folder...
echo Set oWS = WScript.CreateObject("WScript.Shell") > "%TEMP%\create_shortcut.vbs"
echo Set oLink = oWS.CreateShortcut("%shortcut%") >> "%TEMP%\create_shortcut.vbs"
echo oLink.TargetPath = "%install_dir%\deej.exe" >> "%TEMP%\create_shortcut.vbs"
echo oLink.WorkingDirectory = "%install_dir%" >> "%TEMP%\create_shortcut.vbs"
echo oLink.Save >> "%TEMP%\create_shortcut.vbs"

:: Run the VBScript to create the shortcut
cscript //nologo "%TEMP%\create_shortcut.vbs"

:: Clean up VBScript
del "%TEMP%\create_shortcut.vbs"

echo Installation complete! Deej has been installed in "%install_dir%" and will run on startup.
echo.

:: Find the COM port for "Arduino Leonardo"
echo Detecting Arduino Leonardo COM Port... (might take some time, don't close the cmd)
for /f "delims=" %%A in ('powershell -Command "$port = Get-WMIObject Win32_SerialPort | Where-Object { $_.Caption -like '*Arduino*' }; if ($port) { Write-Output $port.DeviceID } else { Write-Output 'NOT_FOUND' }"') do set "arduino_com=%%A"

:: Check if Arduino Leonardo was found
if "%arduino_com%"=="NOT_FOUND" (
    echo ERROR: Arduino Leonardo not found. Check your USB connections and restart deej_installer.bat
    pause
    exit /b
)

echo Arduino Leonardo found on: %arduino_com%

:: Update the config.yaml file with the detected COM port
echo Updating config.yaml...

powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace 'com_port: COM[0-9]+', 'com_port: %arduino_com%' | Set-Content '%install_dir%\config.yaml'"
echo Config file updated successfully!

echo.

:: Modify slider_mapping in config.yaml using a single PowerShell command
echo Updating slider_mapping in config.yaml...

powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '0: master', '0: discord.exe' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '1: chrome.exe', '1: spotify.exe' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '2: spotify.exe', '2:' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '    - rocketleague.exe', '' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '    - pathofexile_x64.exe', '    - rocketleague.exe' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '  3:', '    - pathofexile_x64.exe' | Set-Content '%install_dir%\config.yaml'"
powershell -Command "(Get-Content '%install_dir%\config.yaml') -replace '4: discord.exe', '' | Set-Content '%install_dir%\config.yaml'"

echo.

:: Open the deej folder
echo Opening deej folder...
start explorer "%install_dir%"

pause
