using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace System.Collections
{
    class ArrayListEnumerator : IEnumerator
    {
        ArrayList list;
        int index;
        int count;

        int startIndex;
        int startCount;

        public ArrayListEnumerator(ArrayList al)
        {
            list = al;
            index = -1;
            count = al.Count;
            
            startIndex = -1;
            startCount = al.Count;
        }

        public ArrayListEnumerator(ArrayList al, int index, int count)
        {
            if (count > al.Count + index) throw new IndexOutOfRangeException();

            list = al;
            this.index = index - 1;
            this.count = count;

            startIndex = index - 1;
            startCount = count;
        }

        public object Current
        {
            get { return list[index]; }
        }

        public bool MoveNext()
        {
            if (count == 0) return false;

            index++;
            count--;
            return true;
        }

        public void Reset()
        {
            index = startIndex;
            count = startCount;
        }
    }
}
