struct T {
	public int a, b;
}

struct S {
	T t;

	public T GetT ()
	{
		return t;
	}

	public void Init ()
	{
		t.a = 1;
		t.b = 2;
	}
}

class M {
	public static int Main ()
	{
		S s = new S ();

		s.Init ();

		if (s.GetT ().a != 1)
			return 1;

		if (s.GetT ().b != 2)
			return 2;

		return 200;
	}
}
