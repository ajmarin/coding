using System;
class e092
{
	int[] memo = new int[700];
	int[] q = new int[700];
	static void Main()
	{
        DateTime st = DateTime.Now;
		new e092().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
	int ssd(int x){
		int r = 0, z;
		while(x != 0){
			z = x % 10;
			r += z * z;
			x /= 10;
		}
		return r;
	}
	int dochain(int x){
		int t = 0; x = ssd(x);
		while(x != 1 && x != 89 && memo[x] == -1){
			q[t++] = x;
			x = ssd(x);
		}
		if(x == 1 || x == 89) memo[x] = x;
		for(int j = 0; j < t; ++j) memo[q[j]] = memo[x];
		return memo[x];
	}			
	void solve(){
		int ans = 0;
		for(int i = 0; i < 700; ++i) memo[i] = -1;
		memo[1] = 1; memo[89] = 89;		
		for(int i = 1; i < 10000000; ++i){			
			int z = dochain(i);
			if(z == 89) ++ans;
		}
		Console.WriteLine(ans);
	}				
}
