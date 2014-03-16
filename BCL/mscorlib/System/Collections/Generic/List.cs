using System;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Collections.Generic
{
    public class List<T> : IList<T>, ICollection<T>, IList, ICollection, IReadOnlyList<T>, IReadOnlyCollection<T>, IEnumerable<T>, IEnumerable
    {
        ArrayList list;

        public List()
        {
            list = new ArrayList();
        }

        public List(int capacity)
        {
            list = new ArrayList(capacity);
        }

        public List(IEnumerable<T> collection)
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

        public Enumerator GetEnumerator()
        {
            return new List<T>.Enumerator(list.GetEnumerator());
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
            return new List<T>.Enumerator(list.GetEnumerator());
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

        public struct Enumerator : IEnumerator<T>
        {
            IEnumerator ale;

            public Enumerator(IEnumerator enumerator)
            {
                ale = enumerator;
            }

            public T Current
            {
                get { return (T)ale.Current; }
            }

            public void Dispose()
            {
                
            }

            object IEnumerator.Current
            {
                get { return ale.Current; }
            }

            public bool MoveNext()
            {
                return ale.MoveNext();
            }

            public void Reset()
            {
                ale.Reset();
            }
        }
    }
}
