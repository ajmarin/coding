#include <cstdio>

long long f[14];

int main(void){
	int k, K, N;
	f[0] = 1;
	for(k = 1; k < 14; ++k)
		f[k] = k * f[k - 1];
	while(scanf("%d%d",&K,&N) == 2){
		long long r = f[K];
		for(int i = 0; i < N; ++i){
			scanf("%d",&k);
			r /= f[k];
		}
		printf("%lld\n", r);
	}
	return 0;
}

