#include <cstdio>

long long s[41];
int main(void){
	int N, T;
	s[1] = 1; s[2] = 5; s[3] = 11;
	for(int k = 4; k < 41; ++k)
		s[k] = s[k-1] + (s[k - 2] << 2) + (s[k - 3] << 1);
	scanf("%d",&T);
	while(T--){
		scanf("%d", &N);
		printf("%lld\n",s[N]);
	}
	return 0;
}

