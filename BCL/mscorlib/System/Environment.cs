using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    class Environment
    {
        public static string StackTrace
        {
            get
            {
                return GetStackTrace();
            }
        }
        
        class StackFrame
        {
            public string MethodSignature;
            public string FileName;
            public int LineNumber;
        }

        private static StackFrame GetStackFrame(int i)
        {
            return new StackFrame()
            {
                MethodSignature = GetStackFrameMethodSignature(i),
                FileName = GetStackFrameFileName(i),
                LineNumber = GetStackFrameLineNumber(i)
            };
        }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        push_value32(callstack_size(), CIL_int32);
        ")]
        private static int GetStackFrameCount()
        { return 0; }


        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct StackFrame sf = callstack_at(parameter0);
        push_value32(sf.linenumber, CIL_int32);
        ")]
        private static int GetStackFrameLineNumber(int i)
        { return 0; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct StackFrame sf = callstack_at(parameter0);
        CIL_ldstr(sf.MethodSignature);
        ")]
        private static string GetStackFrameMethodSignature(int i)
        { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        struct StackFrame sf = callstack_at(parameter0);
        CIL_ldstr(sf.filename);
        ")]
        private static string GetStackFrameFileName(int i)
        { return null; }

        [Poly.Internals.CompilerImplemented.InlineCode(@"
        print_callstack();
        ")]
        private static void PrintCallStack()
        { }

        private static string GetStackTrace()
        {            
            string stackTrace = "";
            int sfc = GetStackFrameCount() - 4;
            for (int i = sfc; i >= 0; i--)
            {
                StackFrame fr = GetStackFrame(i);
                stackTrace += "  at " + fr.MethodSignature + "\n";
            }
            return stackTrace;
        }
    }
}
