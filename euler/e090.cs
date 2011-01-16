using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class e090{
	int a, ans = 0, b;
	static void Main(){
        DateTime st = DateTime.Now;
		new e090().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
	bool test(int x, int y){
		int c = 1 << x, d = 1 << y;
		return ((a & c) != 0 && (b & d) != 0) || ((a & d) != 0 && (b & c) != 0);
	}
	int bitcnt(int x){
		int r = 0;
		while(x > 0){
			if((x & 1) != 0) r++;
			x >>= 1;
		}
		return r;
	}
	void solve(){
		for(a = 0; a < 1024; ++a){
			if(bitcnt(a) != 6) continue;
			for(b = a; b < 1024; ++b){
				if(bitcnt(b) != 6) continue;
				if(!test(0, 1)) continue;
				if(!test(0, 4)) continue;
				if(!test(0, 6) && !test(0, 9)) continue;
				if(!test(1, 6) && !test(1, 9)) continue;
				if(!test(2, 5)) continue;
				if(!test(3, 6) && !test(3, 9)) continue;
				if(!test(4, 6) && !test(4, 9)) continue;
				if(!test(6, 4) && !test(9, 4)) continue;
				if(!test(8, 1)) continue;
				ans++;
			}		
		}
		Console.WriteLine(ans);
	}				
}
