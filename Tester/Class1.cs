using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Reflection;

class R
{

}

class U
{
    public int i;
    public R hoi;

    public void test(R t)
    {
        hoi = t;
    }
}

class D
{

    public static int Main(string[] args)
    {
        U u = new U();
        u.hoi = new R();
        u.test(new R());

        return 200;
    }
}
