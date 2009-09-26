#include <cstdio>
int N, M;
int main(void){
	int i, M, N, T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		long long res = 1;
		for(i = 0; i < M; i++){
			long long x = N-M-i;
			res = (res*x)%1300031LL;
		}
		for(i = 0; i < M; i++){
			res = (res<<1)%1300031LL;
		}
		printf("%lld\n",res);
	}
	return 0;
}

