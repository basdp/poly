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
using System.Threading.Tasks;

namespace PolyCompiler
{
    public class Program
    {        
        static void Main(string[] args)
        {
            SDILReader.Globals.LoadOpCodes();

            /*string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
            path = path.Replace("file:\\", "");
            Assembly ass = Assembly.LoadFile(path + "\\Tester.dll");*/
            Assembly ass;
            if (args.Length > 0)
            {
                string input = Path.GetFullPath(args[0]);
                ass = Assembly.LoadFrom(input);
                Console.WriteLine(ass.Location);
            }
            else
            {
                string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
                path = path.Replace("file:\\", "");
                //ass = Assembly.LoadFile(path + "\\Tester.exe");
                ass = Assembly.LoadFrom(@"C:\Users\Bas\Documents\GitHub\poly\BCL\mscorlib\bin\Debug\mscorlib.dll");
            }


            string codefile, headerfile;
            if (args.Length > 0)
            {
                if (args.Length > 1)
                {
                    codefile = args[1] + Path.DirectorySeparatorChar + ass.GetName().Name + ".c";
                    headerfile = args[1] + Path.DirectorySeparatorChar + ass.GetName().Name + ".h";
                    codefile = Path.GetFullPath(codefile);
                    headerfile = Path.GetFullPath(headerfile);
                }
                else
                {
                    codefile = ass.GetName().Name + ".c";
                    headerfile = ass.GetName().Name + ".h";
                    codefile = Path.GetFullPath(codefile);
                    headerfile = Path.GetFullPath(headerfile);

                }
            }
            else
            {
                codefile = "code.c";
                headerfile = "header.h";
            }

            CompilerContext context = new CompilerContext();

            context.Code.Append("#include \"" + headerfile + "\"\n\n");
            context.Header.Append("#pragma once\n#include \"polyruntime.h\"\n#include \"mscorlib.h\"\n\n");

            context.Code.Append("// Imports\n");
            foreach (var export in ass.GetReferencedAssemblies()) {
                context.Code.Append("#include \"" + export.Name + ".h\"\n");
            }

            foreach (Module module in ass.GetModules())
            {
                ModuleGenerator.ProcessModule(module, context);
            }

            context.Code.Append("void init_" + Naming.ConvertTypeToCName(ass.GetName().Name) + "() {\n" + context.Init.ToString() + "\n}\n" + context.Main.ToString() + "\n");

            File.WriteAllText(codefile, context.Code.ToString());
            File.WriteAllText(headerfile, context.Header.ToString());
        }        

        
    }
}
