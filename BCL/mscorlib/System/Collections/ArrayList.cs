using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Collections
{
    /*[Poly.Internals.CompilerImplemented.StructureCode(@"
        int __length;
        uintptr_t* __array;
    ")]*/
    public class ArrayList : IList, ICollection, IEnumerable, ICloneable
    {
        static readonly int DefaultCapacity = 0;
        object[] array;
        int length;

        public ArrayList()
            : this(DefaultCapacity)
        {

        }

        public ArrayList(ICollection other)
        {
            throw new NotImplementedException();
        }

        public ArrayList(int capacity)
        {
            this.array = new object[capacity];
            length = 0;
        }

        public int Add(object value)
        {
            if (length >= array.Length)
            {
                object[] oldarr = array;
                length += 1;
                array = new object[length];
                for (int i = 0; i < length - 1; i++)
                {
                    array[i] = oldarr[i];
                }
            }
            array[length - 1] = value;
            return length - 1;
        }

        public void Clear()
        {
            length = 0;
        }

        public bool Contains(object value)
        {
            return IndexOf(value) != -1;
        }

        public int IndexOf(object value)
        {
            for (int i = 0; i < array.Length; i++)
            {
                if (array[i].Equals(value)) return i;
            }
            return -1;
        }

        public void Insert(int index, object value)
        {
            throw new NotImplementedException();
        }

        public bool IsFixedSize
        {
            get { throw new NotImplementedException(); }
        }

        public bool IsReadOnly
        {
            get { throw new NotImplementedException(); }
        }

        public void Remove(object value)
        {
            throw new NotImplementedException();
        }

        public void RemoveAt(int index)
        {
            throw new NotImplementedException();
        }

        public object this[int index]
        {
            get
            {
                return array[index];
            }
            set
            {
                array[index] = value;
            }
        }

        public void CopyTo(Array array, int index)
        {
            throw new NotImplementedException();
        }

        public int Count
        {
            get { return length; }
        }

        public bool IsSynchronized
        {
            get { throw new NotImplementedException(); }
        }

        public object SyncRoot
        {
            get { throw new NotImplementedException(); }
        }

        public IEnumerator GetEnumerator()
        {
            return new ArrayListEnumerator(this);
        }
        public IEnumerator GetEnumerator(int index, int count)
        {
            return new ArrayListEnumerator(this, index, count);
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return new ArrayListEnumerator(this);
        }

        public object Clone()
        {
            throw new NotImplementedException();
        }
    }
}
