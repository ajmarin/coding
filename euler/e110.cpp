#include <cmath>
#include <cstdio>
#include <ctime>
const int TEST = 10000;
void reduce(long long &x, long long d, int &r){
	for(int fc = 0; ; fc += 2)
		if(!(x % d)) x /= d;
		else { r *= (fc + 1); return; }
}
int nod2(long long x){
	int r = 1;
	reduce(x, 2, r);
	reduce(x, 3, r);
	for(int i = 1; ; ++i){
		long long d1 = 6 * i - 1, d2 = d1 + 2;
		reduce(x, d1, r);
		reduce(x, d2, r);
		if(d2 * d2 > x) break;
	}
	if(x != 1) r *= 3;
	return r;
}
int main(void){
	clock_t ini = clock();
	long long ans = 0; int it = 0;
	/* (1/x) + (1/y) = (1/n)
	** Rephrasing
	** (x + y) / (x * y) = (1 / n)
	** n = xy / (x + y) or
	** y = nx / (x - n)
	** having k = (x - n)
	** y = n*(k + n)/k = n + n^2 / k
	** Therefore y can assume z values where z is the number of
	** divisors of n^2.
	** But, since we don't want duplicates (x, y) (y, x), we'll divide it by
	** two. That will eliminate the trivial solution where k = n, for which
	** we'll add one at the end.
	** Hence, we want the number of divisors of n^2 to be:
	** nod(n^2) / 2 + 1 > 4000000
	** nod(n^2) > 7999998
	*/
	long long k = 2LL * 3 * 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29 * 31 * 37;
	 for(long long i = k; ; i += k)
		if(nod2(i) > 7999998){ ans = i; break; }
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
