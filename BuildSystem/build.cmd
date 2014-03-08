@echo off
copy ..\Release\Runtime.lib .
copy ..\PolyCompiler\bin\Debug\PolyCompiler.exe .
copy ..\PolyCompiler\bin\Debug\Poly.Internals.dll .
copy ..\PolyCompiler\bin\Debug\Tester.exe .
copy ..\BCL\mscorlib\bin\Debug\mscorlib.dll .\mscorlib_.dll

call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat"

rmdir build
mkdir build

cls

cd build

<<<<<<< HEAD
echo Compiling to C

=======
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
..\PolyCompiler.exe ..\mscorlib_.dll
..\PolyCompiler.exe ..\Poly.Internals.dll
..\PolyCompiler.exe ..\Tester.exe

<<<<<<< HEAD
echo Compiling to exe

=======
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
cl /nologo /DEBUG:Yes /O2 /Fomscorlib.obj /I ..\..\Runtime\ /c mscorlib.c
cl /nologo /DEBUG:Yes /O2 /FoPoly.Internals.obj /I ..\..\Runtime\ /c Poly.Internals.c
cl /nologo /DEBUG:Yes /O2 /FoTester.obj /I ..\..\Runtime\ /c Tester.c
rem cl /nologo /DEBUG:Yes /O2 /Fomain.obj /I ..\..\Runtime\ /c ..\main.c

cl /nologo /DEBUG:Yes mscorlib.obj Tester.obj ..\Runtime.lib /FeTester.exe

<<<<<<< HEAD
echo Running...

=======
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
Tester.exe

pause