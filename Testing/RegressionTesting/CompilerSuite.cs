using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace RegressionTesting
{
    class CompilerSuite
    {
        private static string csc = @"C:\Windows\Microsoft.NET\Framework64\v4.0.30319\csc.exe";
        private static string dmcs = @"dmcs";
        private static string mono = @"mono";
        private static string poly = @"PolyCompiler.exe";
        private static string cl = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\bin\cl.exe";
        private static string cl_includes = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\include";
        private static string cl_libs = @"C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib";
        private static string gcc = @"gcc";

        private static string windowsSdkDir {
		get {
			return Microsoft.Win32.Registry.GetValue(@"HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Microsoft SDKs\Windows\v8.1", "InstallationFolder", "").ToString();
		}
	}

        public static string Environment {
		get {
			if (Type.GetType("Mono.Runtime") != null) 
				return "Mono";
			else
				return "Microsoft";
		}
	}

        public static bool Compile(string filename, string output)
        {
            filename = filename.Replace('\\', Path.DirectorySeparatorChar);
            output = output.Replace('\\', Path.DirectorySeparatorChar);

            var file = new FileInfo(filename);

            switch (file.Extension.ToLower())
            {
                case ".cs":
                    {
                        Process proc;
                        if (Environment == "Microsoft")
                        {
                            proc = ExecuteProcess(csc, "/out:" + output + " " + filename);
                        }
                        else if (Environment == "Mono")
                        {
                            proc = ExecuteProcess(dmcs, "-out:" + output + " " + filename);
                        }
                        else
                        {
                            throw new NotImplementedException("Environment " + Environment + " is not supported!");
                        }

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
                        Process proc;
                        if (Environment == "Microsoft")
                        {
                            proc = ExecuteProcess(poly, '"' + filename + '"' + " --out=" + '"' + output + '"');
                        }
                        else if (Environment == "Mono")
                        {
                            proc = ExecuteProcess(mono, poly + " \"" + filename + '"' + " --out=" + '"' + output + '"');
                        }
                        else
                        {
                            throw new NotImplementedException("Environment " + Environment + " is not supported!");
                        }

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
                        Process proc;
                        if (Environment == "Microsoft")
                        {
                            proc = ExecuteProcess(cl, "/nologo /O2 /Fo" + output + @" /I include\ /I """ + cl_includes + "\" /c " + filename + " /link /LIBPATH:\"" + cl_libs + "\"");
                        }
                        else if (Environment == "Mono")
                        {
                            string platform = "-m32";
                            if (System.Environment.GetCommandLineArgs().Length > 0 && System.Environment.GetCommandLineArgs()[0] == "x64")
                            {
                                Console.WriteLine(System.Environment.GetCommandLineArgs()[0]);
                                platform = "-m64";
                            }
                            proc = ExecuteProcess(gcc, platform + " \"" + filename.Replace(@"\", "/") + '"' + " -c -o " + '"' + output.Replace(@"\", "/") + '"' + " -I ../../../Runtime");

                        }
                        else
                        {
                            throw new NotImplementedException("Environment " + Environment + " is not supported!");
                        }

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
                        Process proc;
                        if (Environment == "Microsoft")
                        {
                            proc = ExecuteProcess(cl, "/nologo /O2 " + filename + @" Runtime.lib /Fe" + output + " /link /LIBPATH:\"" + cl_libs + "\" /LIBPATH:\"" + windowsSdkDir + @"\Lib\winv6.3\um\x86" + "\"");
                        }
                        else if (Environment == "Mono")
                        {
                            proc = ExecuteProcess(gcc, " " + filename.Replace(@"\", "/") + ' ' + " runtime.a -o " + '"' + output.Replace(@"\", "/") + '"');
                        }
                        else
                        {
                            throw new NotImplementedException("Environment " + Environment + " is not supported!");
                        }

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
