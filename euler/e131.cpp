#include <cstdio>
#include <ctime>
/* 
Problem:
   find all p's (primes) below 1M such that the following equation
   has integer solutions for n and k:

   n^3 + n^2 p = k^3

   divide by n^2
   n + p = k^3/n^2
   since k^3 has to be divisible by n^2, k has the form x * n^(2/3)
   n + p = (x*n^(2/3))^3 / n^2
   n + p = x^3
   but n is also a cube, therefore:
   p = x^3 - y^3

Problem has been reduced to:
   Find all primes below 1M that are differences of cubes.
*/
const int MAXP = 1000000, ROOT = 1000;
int p[MAXP];
int cube(int x){ return x * x * x; }
int main(void){
	clock_t begin = clock();
	/* Eratosthenes' sieve */
	for(int i = 0; i < MAXP; ++i) p[i] = i > 1;
	for(int i = 4; i < MAXP; i += 2) p[i] = 0;
	for(int i = 3; i < ROOT; i += 2)
		if(p[i]) for(int j = i*i, k = 2*i; j < MAXP; j += k) p[j] = 0;
	/* Solve problem */
	int ans = 0;
	for(int n = 1; n < 578; ++n)
		for(int k = n+1; ; ++k){
			int k3 = cube(k), n3 = cube(n);
			if(k3 - n3 > MAXP) break;
			if(p[k3 - n3]) ++ans;
		}
	printf("Answer: %d\n", ans);
	printf("Time spent: %.3lfs\n", (double)(clock() - begin)/CLOCKS_PER_SEC);
	return 0;
}

