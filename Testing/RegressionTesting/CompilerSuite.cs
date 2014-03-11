using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RegressionTesting
{
    class CompilerSuite
    {
        private static string csc = @"C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe";
        private static string poly = @"PolyCompiler.exe";
        private static string cl = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\cl.exe";
        private static string cl_includes = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include";
        private static string cl_libs = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib";
        private static string windowsSdkDir = Microsoft.Win32.Registry.GetValue(@"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Microsoft SDKs\Windows\v8.1", "InstallationFolder", "").ToString();

        public static bool Compile(string filename, string output)
        {
            var file = new FileInfo(filename);

            switch (file.Extension.ToLower())
            {
                case ".cs":
                    {
                        var proc = ExecuteProcess(csc, "/out:" + output + " " + filename);

                        if (proc.ExitCode != 0)
                        {
                            Console.WriteLine(proc.StandardOutput.ReadToEnd());
                            Console.WriteLine(proc.StandardError.ReadToEnd());
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }

                case ".exe":
                case ".dll":
                    {
                        var proc = ExecuteProcess(poly, '"' + filename + '"' + ' ' + '"' + output + '"');

                        if (proc.ExitCode != 0)
                        {
                            Console.WriteLine(proc.StandardOutput.ReadToEnd());
                            Console.WriteLine(proc.StandardError.ReadToEnd());
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                case ".c":
                    {
                        var proc = ExecuteProcess(cl, "/nologo /Gy /O1 /Os /Fo" + output + @" /I include\ /I """ + cl_includes + "\" /c " + filename + " /link /LIBPATH:\"" + cl_libs + "\"");

                        if (proc.ExitCode != 0)
                        {
                            Console.WriteLine(proc.StandardOutput.ReadToEnd());
                            Console.WriteLine(proc.StandardError.ReadToEnd());
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                case ".obj":
                    {
                        var proc = ExecuteProcess(cl, "/nologo /Gy /OPT:REF /O1 /Os " + filename + @" Runtime.lib /Fe" + output + " /link /LIBPATH:\"" + cl_libs + "\" /LIBPATH:\"" + windowsSdkDir + @"\Lib\winv6.3\um\x86" + "\"");

                        if (proc.ExitCode != 0)
                        {
                            Console.WriteLine(proc.StandardOutput.ReadToEnd());
                            Console.WriteLine(proc.StandardError.ReadToEnd());
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                default:
                    throw new Exception("Don't know how to compile files of type " + file.Extension);
            }
        }

        private static System.Diagnostics.Process ExecuteProcess(string executable, string parameters)
        {
            var comp = new System.Diagnostics.ProcessStartInfo(executable, parameters);
            comp.RedirectStandardOutput = true;
            comp.RedirectStandardError = true;
            comp.CreateNoWindow = true;
            comp.UseShellExecute = false;
            var proc = new System.Diagnostics.Process();
            proc.StartInfo = comp;
            proc.Start();
            proc.WaitForExit(10000);
            if (!proc.HasExited)
            {
                proc.Kill();
            }
            return proc;
        }
    }
}
