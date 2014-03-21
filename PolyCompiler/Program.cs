﻿using Poly.Internals.CompilerImplemented;
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
                ass = Assembly.Load(File.ReadAllBytes(input));
            }
            else
            {
                string path = Path.GetDirectoryName(Assembly.GetAssembly(typeof(Program)).CodeBase);
                path = path.Replace("file:\\", "");
                //ass = Assembly.LoadFile(path + "\\Tester.exe");
                ass = Assembly.Load(File.ReadAllBytes(@"C:\Users\sebdupre\Documents\GitHub\poly\BCL\mscorlib\bin\Debug\__mscorlib.dll"));
            }
            
            string assname = new Regex("^__").Replace(ass.GetName().Name, "").Replace(".__", ".");
            string codefile, headerfile;
            if (args.Length > 0)
            {
                if (args.Length > 1)
                {
                    codefile = args[1] + Path.DirectorySeparatorChar + assname + ".c";
                    headerfile = args[1] + Path.DirectorySeparatorChar + assname + ".h";
                    codefile = Path.GetFullPath(codefile);
                    headerfile = Path.GetFullPath(headerfile);
                }
                else
                {
                    codefile = assname + ".c";
                    headerfile = assname + ".h";
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
            context.Assembly = ass;
            context.CodeHeader.Append("#include \"" + new FileInfo(headerfile).Name + "\"\n\n");
            context.Header.Append("#pragma once\n#include \"polyruntime.h\"\n#include \"mscorlib.h\"\n\n");

            context.CodeHeader.Append("// Imports\n");
            foreach (var export in ass.GetReferencedAssemblies()) {
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

            File.WriteAllText(codefile, context.CodeHeader.ToString() + "\n" + context.Code.ToString());
            File.WriteAllText(headerfile, context.Header.ToString());

            //Console.WriteLine("Output: {0}", codefile);
        }        

        
    }
}
