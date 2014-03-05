using System;
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
                if (t1.FullName.Contains(".__")) t1 = Type.GetType(t1.FullName.Replace(".__", "."));
                if (t2.FullName.Contains(".__")) t2 = Type.GetType(t1.FullName.Replace(".__", "."));
                if (t1.FullName == "System.Object") return -1;
                if (t2.FullName == "System.Object") return 1;
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
                return 0;
            });

            foreach (var type in types)
            {
                TypeGenerator.ProcessTypeDefinitions(type, context);
            }

            foreach (var type in types)
            {
                MethodGenerator.ProcessMethods(type, context);
            }
        }
    }
}
