using System;
class e093
{
	bool[] seen = new bool[360];
	static void Main()
	{
        DateTime st = DateTime.Now;
		new e093().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
	bool permutation(char[] x){
		int k, l; char t;
		for(k = x.Length - 2; k > -1; k--) if(x[k] < x[k + 1]) break;
		if(k == -1) return false;
		for(l = x.Length - 1; l > -1; l--) if(x[k] < x[l]) break;
		t = x[k]; x[k] = x[l]; x[l] = t;
		for(int i = k + 1, j = x.Length - 1; i < j; ++i, --j){
			t = x[i]; x[i] = x[j]; x[j] = t;
		}
		return true;
	}
	int rpn(string x){
		float a, b;
		float[] s = new float[5];
		int t = 0;
		foreach(char c in x){
			if(c >= '0' &&  c <= '9') s[t++] = Convert.ToSingle(c - '0');
			else if(t < 2) return 0;
			else {
				b = s[--t]; a = s[--t];
				if(c == '+')				s[t++] = a + b;
				else if(c == '-')			s[t++] = a - b;
				else if(c == '*')			s[t++] = a * b;
				else if(c == '/' && b != 0) s[t++] = a / b;
				else return 0;
			}
		}
		if(Convert.ToInt16(s[0]) == s[0] && t == 1) return Convert.ToInt16(s[0]);
		return 0;
	}
	void insert(int x){
		if(x > 0 && x < 360) seen[x] = true;
	}
	int doit(char[] x){
		string ops = "+-/*";
		for(int i = 0; i < seen.Length; ++i) seen[i] = false;
		do {
			foreach(char a in ops)
				foreach(char b in ops)
					foreach(char c in ops){
						string s = "" + x[0] + x[1];
						insert(rpn(s + a + x[2] + b + x[3] + c));
						insert(rpn(s + a + x[2] + x[3] + c + b));
						s += x[2];
						insert(rpn(s + b + a + x[3] + c));
						insert(rpn(s + b + x[3] + c + a));
						insert(rpn(s + x[3] + a + b + c));
					}
		} while(permutation(x));
		for(int r = 1; ; ++r) if(!seen[r]) return r - 1;
	}
	void solve()	{
		string ans = "";
		int	n = 0;
		for(char i = '1'; i <= '6'; ++i)
			for(char j = Convert.ToChar(i + 1); j <= '7'; ++j)
				for(char k = Convert.ToChar(j + 1); k <= '8'; ++k)
					for(char l = Convert.ToChar(k + 1); l <= '9'; ++l){
						int r = doit(new char[]{i, j, k, l});
						if(r > n){
							n = r;
							ans = "" + i + j + k + l;
						}
					}
		Console.WriteLine("({0}, #{1})", ans, n);
	}				
}
