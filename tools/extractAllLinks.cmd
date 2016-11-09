@echo off
@REM Because the shell is brain dead, or appears so, I need
@REM to pass each file individually. It cannot cope with a
@REM wildcard list of files such as Keywords*.clean.rst. Sigh.
@REM
for %%f in (*.clean.rst) do @extractLinks %%f
