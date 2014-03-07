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
        public string StackTrace { get; private set; }

        public Exception()
        {
            this.StackTrace = Environment.StackTrace;
        }

        public Exception(string message)
        {
            this.StackTrace = Environment.StackTrace;
            this.Message = message;
        }

        public override string ToString()
        {
            return base.ToString() + "\n" + StackTrace;
        }
    }

    class NotImplementedException : Exception
    {

    }
    class NullReferenceException : Exception
    {

    }
}
