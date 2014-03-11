using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace PolyCompiler
{
    public class CompilerContext
    {
        public CompilerContext()
        {
        }

        public Assembly Assembly;
        public bool IsExecutable = false;

        public Dictionary<FieldInfo, int> Offsets = new Dictionary<FieldInfo, int>();
        public List<Type> CallCctorAtAccess = new List<Type>();
        public List<Type> GenericTypeListGenerated = new List<Type>();
        public StringBuilder Code = new StringBuilder();
        public StringBuilder CodeHeader = new StringBuilder();
        public StringBuilder Header = new StringBuilder();
        public StringBuilder Init = new StringBuilder();
        public StringBuilder Main = new StringBuilder();
    }
}
