@echo off

rmdir build
mkdir build

copy ..\Runtime\Release\Runtime.lib build\
copy ..\PolyCompiler\bin\Debug\PolyCompiler.exe build\
copy ..\PolyCompiler\bin\Debug\Poly.Internals.dll build\
copy ..\Tester\bin\Debug\Tester.exe build\
copy ..\BCL\mscorlib\bin\Debug\mscorlib.dll build\mscorlib_.dll

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

cls

cd build

echo Compiling to C

PolyCompiler.exe mscorlib_.dll
PolyCompiler.exe Poly.Internals.dll
PolyCompiler.exe Tester.exe

echo Compiling to exe

cl /nologo /Gy /O1 /Os /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /Gy /O1 /Os /FoPoly.Internals.obj /I ..\..\Runtime\ /c Poly.Internals.c
cl /nologo /Gy /O1 /Os /FoTester.obj /I ..\..\Runtime\ /c Tester.c

cl /nologo /Gy /O1 /Os mscorlib.obj Tester.obj Runtime.lib /FeTester.poly.exe

echo Running...

Tester.poly.exe

pause