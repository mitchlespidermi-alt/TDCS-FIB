call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\VCVARSALL.BAT" amd64

cd .
nmake -f DCU1.mk  MODELLIB=DCU1lib.lib RELATIVE_PATH_TO_ANCHOR=.. MODELREF_TARGET_TYPE=NONE
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
