#pragma warning disable 1685,0436

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    class Exception
    {
        public string Message { get; set; }
        public string HelpLink { get; set; }
        public int HResult { get; protected set; }
        public Exception InnerException { get; private set; }
        public string Source { get; set; }
        public virtual string StackTrace { get; private set; }

        public Exception()
        {
            this.StackTrace = "(unknown)";
        }

        public Exception(string message)
        {
            this.StackTrace = "(unknown)";
            this.Message = message;
        }

        public override string ToString()
        {
            return base.ToString() + "\n" + StackTrace;
        }

        protected void InitStackTrace()
        {
            this.StackTrace = Environment.StackTrace;
            //string stacktrace = Environment.StackTrace;
            //this.StackTrace = stacktrace.Substring(stacktrace.IndexOf("\n") + 1);
        }
    }

    class __NotImplementedException : Exception
    {

    }
    class __NullReferenceException : Exception
    {

    }
    class __InvalidCastException : Exception
    {

    }
}
