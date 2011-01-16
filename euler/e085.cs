using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class e085
{
	static void Main()
	{
        DateTime st = DateTime.Now;
		new e085().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
	void solve()
	{
		int ans = 0, md = 2000000;
        for(int x = 1; x < 100; ++x)
			for(int y = 1; y < 100; ++y){
				int z = x * y * (x + 1) * (y + 1) >> 2;
				if(Math.Abs(z - 2000000) < md){
					md = Math.Abs(z - 2000000);
					ans = x * y;
				}
			}
		Console.WriteLine(ans);
	}				
}
