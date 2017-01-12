@echo off
REM ----------------------------------------------------------------------------
REM  A Windows script to compile all the cpp files into exe versions.
REM  Assumes that your compiler is on %PATH%.
REM ----------------------------------------------------------------------------
REM  Norman Dunbar    2nd September 2016.
REM ----------------------------------------------------------------------------

REM ----------------------------------------------------------------------------
REM  What is the command to run your compiler front end?
REM ----------------------------------------------------------------------------
REM  Change this to suit, the default is the free Borland c++ compiler version 
REM  10.1 which you can get free from embarcadero.com. 
REM  It's up to date which Visual C++ will never ever be.
REM ----------------------------------------------------------------------------
set compiler=bcc32c

REM ----------------------------------------------------------------------------
REM  Compile everything cpp-ish, and tidy away the surplus files.
REM ----------------------------------------------------------------------------
REM  Read back each file, stripping off the .cpp extension.
REM  This assumes that the filename appears, in full, before the first dot.
REM ----------------------------------------------------------------------------
for /f "tokens=1 delims=." %%f in ('dir /b *.cpp') do (
    echo Compiling %%f.cpp to %%f.exe ...
    %compiler% -o %%f.exe %%f.cpp wildargs.obj
    
    if not %errorlevel%==0 (
        echo Compiler exited with errorlevel %ERRORLEVEL%.
    )
    
    del %%f.tds 2>nul
 
)

pause