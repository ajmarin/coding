#include <cstdio>
#include <cstring>
#define MAXN 3000001
#define SMAXN 5478
bool sieve[MAXN];
int p[216815];
int main(void){
	int c, i, j, r, pc= 0;
	long long N;
	memset(sieve,1,MAXN);
	for(i = 3; i < SMAXN; i+=2)
		if(sieve[i])
			for(p[pc++] = i, j = i*i; j < MAXN; j+=i)
				sieve[j] = 0;
	for(i = SMAXN+1; i < MAXN; i+=2)
		if(sieve[i]) p[pc++] = i;
	while(scanf("%lld",&N)==1){
		r = 1;
		if(N) while(!(N&1)) N>>=1;
		if(N) for(i = 0; i < pc; i++)
			if(!(N%p[i])){
				c = 0;
				do {
					N/=p[i], c++;
				}while(!(N%p[i]));
				r *= (c+1);
				if(N == 1 || (N < MAXN && sieve[N]))
					break;
			}
		r <<= (N>1);
		printf("%d\n",r);
	}
	return 0;
}

