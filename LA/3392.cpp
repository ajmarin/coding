#include <cstdio>

#define NN 302
long long tri[NN];
int main(void){
	for(int i = 1; i < NN; ++i) tri[i] = (i*(i+1))/2;
	for(int i = 2; i < NN; ++i) tri[i] *= (i-1);
	int T, N;
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		long long acc = 0;
		for(int i = 1; i <= N; ++i) acc += tri[i+1];
		printf("%d %d %d\n",++cnum,N,acc);
	}
	return 0;
}

