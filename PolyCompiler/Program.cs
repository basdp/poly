using NDesk.Options;
using Poly.Internals.CompilerImplemented;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace PolyCompiler
{
    public class Program
    {
        private static int verbosity = 0;
        private static int debuglevel = 0;
        private static string entryClass = null;
        private static bool noMain = false;

        static int Main(string[] args)
        {
            SDILReader.Globals.LoadOpCodes();

            bool show_help = false, show_version = false;
            string outputdir = ".";
            CompilerContext.Architectures arch = IntPtr.Size == 8 ? CompilerContext.Architectures.X64 : CompilerContext.Architectures.X86;
            
            var p = new OptionSet() {
                { 
                    "o|out=", "the {OUTPUT} directory for the .c and .h files.",
                    v => outputdir = v 
                },
                {
                    "arch=", "the processor {ARCHITECTURE} to target.\n valid architectures: " + string.Join(", ", Enum.GetNames(typeof(CompilerContext.Architectures))),
                    delegate(string v) {
                        if (!Enum.TryParse(v, true, out arch))
                        {
                            Console.Error.WriteLine("PolyCompiler: error: " + v + ": not a valid architecture");
                            Environment.Exit(1);
                        } 
                    }
                },
                {
                    "v", "increase debug message verbosity",
                    v => { if (v != null) ++verbosity; } 
                },
                {
                    "debug", "generate debugging code",
                    v => { if (v != null) ++debuglevel; } 
                },
                {
                    "main=", "tell the compiler which {CLASS} contains the Main(...) entry point",
                    v => { entryClass = v; } 
                },
                {
                    "nomain", "do not generate an entry point, even if a Main(...) method has been found",
                    v => { if (v != null) noMain = true; } 
                },
                {
                    "h|help",  "show this message and exit", 
                    v => show_help = v != null 
                },
                {
                    "V|version",  "print the version and exit", 
                    v => show_version = v != null 
                },
            };

            List<string> input_files = new List<string>();
            try
            {
                input_files = p.Parse(args);
            }
            catch (OptionException e)
            {
                Console.Write("PolyCompiler: error: ");
                Console.WriteLine(e.Message);
                Console.WriteLine("Try `PolyCompiler --help' for more information.");
                return 1;
            }

            if (show_help)
            {
                ShowHelp(p);
                return 0;
            }

            if (show_version)
            {
                ShowVersion(p);
                return 0;
            }

            if (input_files.Count == 0)
            {
                System.Console.Error.WriteLine("PolyCompiler: no input files");
                return 1;
            } 

            foreach (var filename in input_files)
            {
                Assembly ass;

                try
                {
                    string input = Path.GetFullPath(filename);
                    ass = Assembly.Load(File.ReadAllBytes(input));
                }
                catch (Exception e)
                {
                    System.Console.Error.WriteLine("PolyCompiler: error: " + filename +": no such file or directory");
                    System.Console.Error.WriteLine(e.Message);
                    return 1;
                }

                /*string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
                path = path.Replace("file:\\", "");
                //ass = Assembly.LoadFile(path + "\\Tester.exe");
                ass = Assembly.Load(File.ReadAllBytes(@"C:\Users\sebdupre\Documents\GitHub\poly\BCL\mscorlib\bin\Debug\__mscorlib.dll"));*/
                
                string assname = new Regex("^__").Replace(ass.GetName().Name, "").Replace(".__", ".");
                string codefile, headerfile;

                if (!Directory.Exists(outputdir)) Directory.CreateDirectory(outputdir);

                codefile = outputdir + Path.DirectorySeparatorChar + assname + ".c";
                headerfile = outputdir + Path.DirectorySeparatorChar + assname + ".h";
                codefile = Path.GetFullPath(codefile);
                headerfile = Path.GetFullPath(headerfile);

                CompilerContext context = new CompilerContext();

                context.Architecture = arch;
                context.DebugLevel = debuglevel;
                context.EntryClass = entryClass;
                context.DoNotGenerateMain = noMain;

                context.Assembly = ass;
                context.CodeHeader.Append("#include \"" + new FileInfo(headerfile).Name + "\"\n\n");
                context.Header.Append("#pragma once\n#include \"polyruntime.h\"\n#include \"mscorlib.h\"\n\n");

                context.CodeHeader.Append("// Imports\n");
                foreach (var export in ass.GetReferencedAssemblies())
                {
                    context.CodeHeader.Append("#include \"" + export.Name + ".h\"\n");
                }

                foreach (Module module in ass.GetModules())
                {
                    ModuleGenerator.ProcessModule(module, context);
                }

                foreach (var assembly in context.Assembly.GetReferencedAssemblies())
                {
                    context.Init.AppendLine("    init_" + Naming.ConvertTypeToCName(assembly.Name) + "();");
                }

                context.Code.AppendLine("int init_" + Naming.ConvertTypeToCName(assname) + "__called = 0;");
                context.Code.Append("void init_" + Naming.ConvertTypeToCName(assname) + "() {\n    if(init_" + Naming.ConvertTypeToCName(assname) + "__called) return;\n    init_" + Naming.ConvertTypeToCName(assname) + "__called = 1;\n" + context.Init.ToString() + "}\n" + context.Main.ToString() + "\n");
                context.Header.AppendLine("void init_" + Naming.ConvertTypeToCName(assname) + "();");

                File.WriteAllText(codefile, context.CodeHeader.ToString() + "\n" + context.Code.ToString());
                File.WriteAllText(headerfile, context.Header.ToString());

            }
            //Console.WriteLine("Output: {0}", codefile);

            return 0;
        }

        private static void ShowHelp(OptionSet p)
        {
            Console.WriteLine("Usage: PolyCompiler.exe [OPTIONS] assemblies");
            Console.WriteLine("Compile .NET assemblies (.exe or .dll) to .c and .h files to use with the Poly Framework.");
            Console.WriteLine();
            Console.WriteLine("Options:");
            p.WriteOptionDescriptions(Console.Out);
        }

        private static void ShowVersion(OptionSet p)
        {
            var version = Assembly.GetEntryAssembly().GetName().Version;
            var product = ((AssemblyProductAttribute)Assembly.GetEntryAssembly().GetCustomAttribute(typeof(AssemblyProductAttribute))).Product;
            var copyright = ((AssemblyCopyrightAttribute)Assembly.GetEntryAssembly().GetCustomAttribute(typeof(AssemblyCopyrightAttribute))).Copyright;
            Console.WriteLine(product + " " + version.Major + "." + version.Minor + "." + version.Build + " (build " + version.Revision + ")");
            Console.WriteLine(copyright);
        }
        
        static void Debug(string format, params object[] args)
        {
            if (verbosity > 0)
            {
                Console.Write("# ");
                Console.WriteLine(format, args);
            }
        }

    }
}
