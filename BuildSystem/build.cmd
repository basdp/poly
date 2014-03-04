@echo off
copy ..\Release\Runtime.lib .
copy ..\PolyCompiler\bin\Debug\PolyCompiler.exe .
copy ..\PolyCompiler\bin\Debug\Poly.Internals.dll .
copy ..\PolyCompiler\bin\Debug\Tester.dll .
copy ..\BCL\mscorlib\bin\Debug\mscorlib.dll .\mscorlib_.dll

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

rmdir build
mkdir build

cls

cd build

..\PolyCompiler.exe ..\mscorlib_.dll mscorlib.c mscorlib.h
..\PolyCompiler.exe ..\Poly.Internals.dll Poly.Internals.c Poly.Internals.h
..\PolyCompiler.exe ..\Tester.dll Tester.c Tester.h

cl /nologo /O2 /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /O2 /FoPoly.Internals.obj /I ..\..\Runtime\ /c Poly.Internals.c
cl /nologo /O2 /FoTester.obj /I ..\..\Runtime\ /c Tester.c
cl /nologo /O2 /Fomain.obj /I ..\..\Runtime\ /c ..\main.c

cl /nologo /DEBUG:Yes mscorlib.obj Tester.obj main.obj ..\Runtime.lib /FeTester.exe

Tester.exe

pause