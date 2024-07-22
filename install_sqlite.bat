@echo off
setlocal

REM Set the destination folder where sqlite3 will be installed
set "DEST_FOLDER=.\Employee Database\lib\sqlite\"

REM Create the destination folder if it does not exist
if not exist "%DEST_FOLDER%" (
    mkdir "%DEST_FOLDER%"
)

REM Set the URL for the sqlite3 download
set "SQLITE_URL=https://www.sqlite.org/2023/sqlite-amalgamation-3420000.zip"

REM Set the temporary folder for download and extraction
set "TEMP_FOLDER=%TEMP%\sqlite_temp"

REM Create the temporary folder
if not exist "%TEMP_FOLDER%" (
    mkdir "%TEMP_FOLDER%"
)

REM Download the sqlite3 zip file
echo Downloading sqlite3...
powershell -Command "Invoke-WebRequest -Uri %SQLITE_URL% -OutFile %TEMP_FOLDER%\sqlite.zip"

REM Extract the downloaded zip file
echo Extracting sqlite3...
powershell -Command "Expand-Archive -Path %TEMP_FOLDER%\sqlite.zip -DestinationPath %TEMP_FOLDER%"

REM Move the extracted files to the destination folder
echo Installing sqlite3...
move /Y "%TEMP_FOLDER%\sqlite-amalgamation-3420000\*" "%DEST_FOLDER%"

REM Clean up the temporary folder
echo Cleaning up...
rmdir /S /Q "%TEMP_FOLDER%"

echo sqlite3 installation complete.

endlocal
pause