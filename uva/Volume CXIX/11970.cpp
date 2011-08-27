#include <cstdio>
#include <cmath>

const int LIM = 31623; // 10**4.5
int sqr[31623];
int main(void){
	for(int i = 0; i < LIM; ++i) sqr[i] = i*i;
	int T, n, z;
	scanf("%d", &T);
	for(int cnum = 0; cnum++ < T; ){
		printf("Case %d:", cnum);
		scanf("%d", &n);
		for(int u = 0, v = LIM; u < v; ){
			z = (u + v) >> 1;
			if(sqr[z] < n) u = z + 1; else v = z;
		}
		z -= sqr[z] >= n;
		for(; z > 0; --z){
			int x = n - sqr[z];
			if(!(x % z)) printf(" %d", x);
		}
		puts("");
	}
	return 0;
}

