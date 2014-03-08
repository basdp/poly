#pragma warning disable 1685,0436

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
<<<<<<< HEAD
    class __Exception
=======
    class Exception
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
    {
        public string Message { get; set; }
        public string HelpLink { get; set; }
        public int HResult { get; protected set; }
        public Exception InnerException { get; private set; }
        public string Source { get; set; }
<<<<<<< HEAD
        public virtual string StackTrace { get; private set; }

        public __Exception()
        {
            this.StackTrace = "(unknown)";
        }

        public __Exception(string message)
        {
            this.StackTrace = "(unknown)";
=======
        public string StackTrace { get; private set; }

        public Exception()
        {
            this.StackTrace = Environment.StackTrace;
        }

        public Exception(string message)
        {
            this.StackTrace = Environment.StackTrace;
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
            this.Message = message;
        }

        public override string ToString()
        {
            return base.ToString() + "\n" + StackTrace;
        }
<<<<<<< HEAD

        protected void InitStackTrace()
        {
            //this.StackTrace = Environment.StackTrace;
            string stacktrace = Environment.StackTrace;
            this.StackTrace = stacktrace.Substring(stacktrace.IndexOf("\n") + 1);
        }
    }

    class __NotImplementedException : __Exception
    {

    }
    class __NullReferenceException : __Exception
    {

    }
    class __InvalidCastException : __Exception
    {

    }
    class __IndexOutOfRangeException : __Exception
    {

    }
    class __ArgumentOutOfRangeException : __Exception
=======
    }

    class __NotImplementedException : Exception
    {

    }
    class __NullReferenceException : Exception
    {

    }
    class __InvalidCastException : Exception
>>>>>>> c2b351a7678081326d30d337f4c1b52610b82019
    {

    }
}
