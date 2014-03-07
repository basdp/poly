using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System
{
    class Type
    {
        public string FullName { get; protected set; }

        public Type(string fullName)
        {
            FullName = fullName;
        }

        public bool Equals(Type other)
        {
            return FullName == other.FullName;
        }

        public virtual bool IsSubclassOf(Type c)
        {
            throw new NotImplementedException();
        }

        public virtual bool IsInstanceOfType(Object o)
        {
            throw new System.NotImplementedException();
        }


    }
}
