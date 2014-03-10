struct A
{
	public A(int i)
	{
		this.i = i;
		this.j = i;
		this.k = i;
	}

	public int i;
	public int j;
	public int k;
}

class X
{
	public static int test(A a)
	{
		a.j = 5;
		return 34;
	}

	public static int Main(string[] args)
	{
		A a;
		a.i = 4;
		a.j = 0;
		a.k = 0;

		test(a);

		System.Console.WriteLine(a.i);
		System.Console.WriteLine(a.j);

		if (a.i != 4) return 1;
		if (a.j != 0) return 1;
		
        return 200;
    }
}
