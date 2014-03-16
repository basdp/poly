using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Collections.Generic
{
    public class __List<T> : IList<T>, ICollection<T>, IList, ICollection, IReadOnlyList<T>, IReadOnlyCollection<T>, IEnumerable<T>, IEnumerable
    {
        T listk;
        ArrayList list;

        public __List()
        {
            list = new ArrayList();
        }

        public __List(int capacity)
        {
            list = new ArrayList(capacity);
        }

        public __List(IEnumerable<T> collection)
        {
            list = new ArrayList();
            foreach (object o in collection) list.Add(o);
        }

        public int IndexOf(T item)
        {
            return list.IndexOf(item);
        }

        public void Insert(int index, T item)
        {
            list.Insert(index, item);
        }

        public void RemoveAt(int index)
        {
            list.RemoveAt(index);
        }

        public T this[int index]
        {
            get
            {
                return (T)list[index];
            }
            set
            {
                list[index] = value;
            }
        }

        public void Add(T item)
        {
            list.Add(item);
        }

        public void Clear()
        {
            list.Clear();
        }

        public bool Contains(T item)
        {
            return list.Contains(item);
        }

        public void CopyTo(T[] array, int arrayIndex)
        {
            list.CopyTo(array, arrayIndex);
        }

        public int Count
        {
            get { return list.Count; }
        }

        public bool IsReadOnly
        {
            get { return list.IsReadOnly; }
        }

        public bool Remove(T item)
        {
            int size = list.Count;
            list.Remove(item);
            return list.Count != size;
        }

        public IEnumerator<T> GetEnumerator()
        {
            throw new NotImplementedException();
        }

        IEnumerator IEnumerable.GetEnumerator()
        {
            return list.GetEnumerator();
        }

        void ICollection<T>.Add(T item)
        {
            list.Add(item);
        }

        void ICollection<T>.Clear()
        {
            list.Clear();
        }

        bool ICollection<T>.Contains(T item)
        {
            return list.Contains(item);
        }

        void ICollection<T>.CopyTo(T[] array, int arrayIndex)
        {
            list.CopyTo(array, arrayIndex);
        }

        int ICollection<T>.Count
        {
            get { return list.Count; }
        }

        bool ICollection<T>.IsReadOnly
        {
            get { return list.IsReadOnly; }
        }

        bool ICollection<T>.Remove(T item)
        {
            int size = list.Count;
            list.Remove(item);
            return list.Count != size;
        }

        IEnumerator<T> IEnumerable<T>.GetEnumerator()
        {
            throw new NotImplementedException();
        }

        public int Add(object value)
        {
            return list.Add(value);
        }

        public bool Contains(object value)
        {
            return list.Contains(value);
        }

        public int IndexOf(object value)
        {
            return list.IndexOf(value);
        }

        public void Insert(int index, object value)
        {
            list.Insert(index, value);
        }

        public bool IsFixedSize
        {
            get { return list.IsFixedSize; }
        }

        public void Remove(object value)
        {
            list.Remove(value);
        }

        object IList.this[int index]
        {
            get
            {
                return list[index];
            }
            set
            {
                list[index] = value;
            }
        }

        public void CopyTo(Array array, int index)
        {
            list.CopyTo(array, index);
        }

        public bool IsSynchronized
        {
            get { return list.IsSynchronized; }
        }

        public object SyncRoot
        {
            get { return list.SyncRoot; }
        }

        T IReadOnlyList<T>.this[int index]
        {
            get { return (T)list[index]; }
        }

        int IReadOnlyCollection<T>.Count
        {
            get { return list.Count; }
        }
    }
}
