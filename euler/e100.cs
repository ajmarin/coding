using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


class e100
{
	static void Main()
	{
        DateTime st = DateTime.Now;
		new e100().solve();
        TimeSpan ts = DateTime.Now - st;
        Console.WriteLine("Elapsed time: {0}ms",
            ts.Hours * 3600000 + ts.Minutes * 60000 + 
            ts.Seconds * 1000 + ts.Milliseconds);
	}
    long f(long x)
    {
        double k = (double)x;
        return (long)Math.Sqrt(1 + 8 * k * k);
    }
	void solve()
	{
        /*
         * B = Blue balls, R = Red balls
         * 2 * B * (B - 1) = (B + R) * (B + R - 1)
         * 2 * (B*B - B) = (B*B + 2BR + R*R - (B + R))
         * B*B - (2R + 1) B + R - R*R = 0
         * 8R*R + 1 must be a perfect square
         * B + R > 10^12
         * R is at least 10^6 since B > R
         * First solutions for 8R*R + 1 are
         * 0, 1, 6, 35, 204, 1189, 6930, ...
         * and the sequence has the recurrence formula
         * T(n) = 6 * T(n - 1) - T(n - 2)
        */
        long B, P1 = 6, P2 = 1, R;
        while(true){
            R = 6 * P1 - P2;
            P2 = P1;
            P1 = R;
            B = (R + R + 1 + f(R)) >> 1;
            Console.WriteLine("B = {0,15}, R = {1,15}", B, R);
            if (B + R > 1000000000000) break;
        }
        Console.WriteLine("Blue balls\t: {0, 15}", B);
        Console.WriteLine("Red balls\t: {0, 15}", R);
        Console.WriteLine("Total\t\t: {0, 15}", B + R);
		Console.WriteLine(B);
	}				
}
