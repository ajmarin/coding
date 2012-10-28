#include <cstdio>

const int LIM = 1048576, ROOT = 1024;
bool p[LIM];
int pL[LIM >> 3], pLC = 0;

long long sqr(int i){ return (long long)i * i; }

int main(void){
	for(int i = 2; i < LIM; ++i) p[i] = i & 1;
	p[2] = true;
	for(int i = 3; i < ROOT; ++i) if(p[i]){
		for(int j = i * i, k = i << 1; j < LIM; j += k)
			p[j] = false;
	}
	for(int i = 2; i < LIM; ++i) if(p[i]) pL[pLC++] = i;
	scanf("%*d");
	for(long long low, high; scanf("%lld %lld", &low, &high) == 2; ){
		int ans = 0;
		for(int i = 0; i < pLC && sqr(pL[i]) <= high; ++i){
			for(long long j = sqr(pL[i]); j <= high; j *= pL[i])
				ans += j >= low;
		}
		printf("%d\n", ans);
	}

	return 0;
}

