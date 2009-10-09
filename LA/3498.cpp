#include <cstdio>
#include <cstring>

long long ans[12], p[2048];
int L, N;
long long poss(int mask){
	if(p[mask]) return p[mask];
	//printf("Called with %d\n",mask);
	long long ret = 0;
	for(int c = 1; c < L; ++c)
		if(!(c & mask)) ret += 1 + poss(mask|c);
	p[mask] = ret;
	return p[mask];
}

			
int main(void){
	int T;
	scanf("%d",&T);
	for(int i = 1; i < 12; i++){
		N = i;
		L = 1<<i;
		memset(p, 0, sizeof(p));
		ans[i] = poss(0);
	}
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		printf("%d %d %lld\n",++cnum,N,ans[N]);
	}
	return 0;
}
