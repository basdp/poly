@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat"

copy ..\Release\Runtime.lib .

cls

cd build

cl /nologo /O2 /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /O2 /FoTester.obj /I ..\..\Runtime\ /c Tester.c
cl /nologo /O2 /Fomain.obj /I ..\..\Runtime\ /c ..\main.c

cl /nologo mscorlib.obj Tester.obj main.obj ..\Runtime.lib /FeTester.exe

tester.exe

pause