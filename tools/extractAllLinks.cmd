@echo off
REM
REM Extract the links from all the RST docs. Assumes
REM that we are currently in the tools folder.
REM Writes a sorted list to ..\sphinx\source\AllLinks.txt
REM
set OLD_PWD=%CD%
cd ..\sphinx\source
extractKeywords *.rst | sort > allLinks.txt
cd %OLD_PWD%
