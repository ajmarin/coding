using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

class e089
{
	int[] value = new int[128];
	static void Main()
	{
        DateTime st = DateTime.Now;
		new e089().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
	void solve()
	{
		int ans = 0;
		TextReader tr = new StreamReader("roman.txt");
		/* Table of values */
		value['I'] = 1;		value['V'] = 5;		value['X'] = 10;
		value['L'] = 50;	value['C'] = 100;	value['D'] = 500;
		value['M'] = 1000;
		for(string s = tr.ReadLine(); s != null; s = tr.ReadLine()){
			int v1, v2, z = 0;
			for(int i = 0; i < s.Length; ++i){
				v1 = value[(int)s[i]];
				if(s[i] == 'I' || s[i] == 'X' || s[i] == 'C'){
					if(i + 1 == s.Length) z += v1;
					else {
						v2 = value[(int)s[i + 1]];
						if(v2 > v1){
							++i;
							z += v2 - v1;
						}
						else z += v1;
					}
				} else z += v1;
			}
			string c = "";
			while (z >= 1000)	{ 	z -= 1000; 	c += "M";	}
			while (z >= 900)	{ 	z -= 900; 	c += "CM";	}
			while (z >= 500)	{ 	z -= 500; 	c += "D";	}
			while (z >= 400)	{ 	z -= 400; 	c += "CD";	}
			while (z >= 100)	{ 	z -= 100; 	c += "C";	}
			while (z >= 90)		{	z -= 90; 	c += "XC";	}
			while (z >= 50)		{	z -= 50; 	c += "L";	}
			while (z >= 40)		{	z -= 40; 	c += "XL";	}
			while (z >= 10)		{	z -= 10; 	c += "X";	}
			while (z >= 9)		{	z -= 9; 	c += "IX";	}
			while (z >= 5)		{	z -= 5; 	c += "V";	}
			while (z >= 4)		{	z -= 4; 	c += "IV";	}
			while (z > 0)		{	z -= 1;		c += "I";	}
			ans += s.Length - c.Length;
		}
		Console.WriteLine(ans);
	}				
}
