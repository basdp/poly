@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

copy ..\Release\Runtime.lib .

cls

cd build

cl /nologo /O2 /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /O2 /FoPoly.Internals.obj /I ..\..\Runtime\ /c Poly.Internals.c
cl /nologo /O2 /FoTester.obj /I ..\..\Runtime\ /c Tester.c
rem cl /nologo /O2 /Fomain.obj /I ..\..\Runtime\ /c ..\main.c

cl /nologo /DEBUG:Yes mscorlib.obj Tester.obj ..\Runtime.lib /FeTester.exe

Tester.exe

pause