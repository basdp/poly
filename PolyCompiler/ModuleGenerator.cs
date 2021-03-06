﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    class ModuleGenerator
    {
        public static void ProcessModule(Module module, CompilerContext context)
        {
            context.Code.Append("// module " + module.FullyQualifiedName + "\n\n");
            context.Header.Append("// module " + module.FullyQualifiedName + "\n\n");

            List<Type> types = module.GetTypes().ToList();
            types.Sort(delegate(Type t1, Type t2)
            {
                if (t1 == null && t2 == null) return 0;
                if (t1 == null) return 1;
                if (t2 == null) return -1;

                if (Naming.GetFullName(t1).Contains(".__"))
                {
                    string tname = Naming.GetFullName(t1).Replace(".__", ".");
                    t1 = t1.Assembly.GetType(tname);
                    if (t1 == null)
                    {
                        // This is a renamed mscorlib type
                        t1 = new Object().GetType().Assembly.GetType(tname);
                    }
                }
                if (Naming.GetFullName(t2).Contains(".__"))
                {
                    string tname = Naming.GetFullName(t2).Replace(".__", ".");
                    t2 = t2.Assembly.GetType(tname);
                    if (t2== null)
                    {
                        // This is a renamed mscorlib type
                        t2 = new Object().GetType().Assembly.GetType(tname);
                    }
                }

                if (t1.FullName == "System.Object") return -1;
                if (t2.FullName == "System.Object") return 1;

                if (t1.FullName == "System.ValueType") return -1;
                if (t2.FullName == "System.ValueType") return 1;

                if (t1.IsSubclassOf(t2))
                {
                    return 1;
                }
                else if (t1 == t2)
                {
                    return 0;
                }
                else if (t2.IsSubclassOf(t1))
                {
                    return -1;
                }

                FieldInfo[] fis1 = t1.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);
                FieldInfo[] fis2 = t1.GetFields(BindingFlags.DeclaredOnly | BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance);

                foreach (var fi in fis1)
                {
                    if (fi.FieldType.IsValueType && fi.FieldType == t2)
                        return 1;
                }

                foreach (var fi in fis2)
                {
                    if (fi.FieldType.IsValueType && fi.FieldType == t1)
                        return -1;
                }

                int depth1 = 0;
                Type base1 = t1.BaseType;
                while (base1 != null)
                {
                    depth1++;
                    base1 = base1.BaseType;
                }
                int depth2 = 0;
                Type base2 = t2.BaseType;
                while (base2 != null)
                {
                    depth2++;
                    base2 = base2.BaseType;
                }

                return depth1.CompareTo(depth2);
            });

            foreach (var type in types)
            {
                TypeGenerator.ProcessTypeDefinition(type, context);
            }

            foreach (var type in types)
            {
                MethodGenerator.ProcessMethods(type, context);
            }
        }
    }
}
