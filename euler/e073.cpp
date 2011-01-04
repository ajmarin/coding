#include <cmath>
#include <cstdio>
#include <ctime>

const int L = 12001;
int gcd(int n,int m){ return m ? gcd(m, n % m) : n;}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int d = 1; d < L; ++d){
		int l = d / 3 + 1, r = ((d + 1) >> 1);
		for(int n = l; n < r; ++n)
			ans += gcd(n, d) == 1;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

