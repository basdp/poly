@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

copy ..\Runtime\Release\Runtime.lib build

cls

cd build

cl /nologo /Od /Z7 /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /Od /Z7 /FoPoly.Internals.obj /I ..\..\Runtime\ /c Poly.Internals.c
cl /nologo /Od /Z7 /FoTester.obj /I ..\..\Runtime\ /c Tester.c

cl /nologo /Z7 /DEBUG:Yes mscorlib.obj Tester.obj ..\Runtime.lib /FeTester.poly.exe

Tester.poly.exe

pause