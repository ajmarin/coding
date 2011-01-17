using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

struct Point{
	public int x, y;
	public Point(int a, int b)
	{
		x = a;
		y = b;
	}
	public static Point operator -(Point a, Point b)
	{
		return new Point(a.x - b.x, a.y - b.y);
	}
	public static int operator *(Point a, Point b)
	{
		return a.x * b.x + a.y * b.y;
	}
}
class e091
{
	static void Main()
	{
		new e091().solve();
	}
	bool right_angle(Point a, Point b, Point c){
		if ((b - a) * (c - a) == 0) return true;
		if ((c - b) * (a - b) == 0) return true;
		if ((a - c) * (b - c) == 0) return true;
		return false;
	}
	void solve()
	{
		int ans = 0, gs = 51, l = gs * gs;
		Point o, a, b;
		o = new Point(0, 0);
		a = new Point(0, 0);
		b = new Point(0, 0);
		for (int i = 1; i < l; ++i)
			for (int j = i + 1; j < l; ++j)
			{
				a.x = i / gs; a.y = i % gs;
				b.x = j / gs; b.y = j % gs;
				if (right_angle(o, a, b)) ans++;
			}
		Console.WriteLine(ans);
		Console.ReadLine();
	}
}
