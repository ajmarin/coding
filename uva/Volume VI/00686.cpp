/////////////////////////////////
// 00686 - Goldbach's Conjecture (II)
/////////////////////////////////
#include<cstdio>
#define MAX 1000001
int i,j,n, lim = 1001, pos = 0, count;
int primes[78498];
bool sieve[MAX];
void build_sieve(){
	primes[0] = 2;
	for(i = 4; i < MAX; i+=2) sieve[i] = true;
	for(i = 3; i < MAX; i+=2)
		if(!sieve[i]){
			primes[++pos] = i;
			if(i < lim) for(j = i*i; j < MAX; j+=i) sieve[j] = true;
		}
}
int main(void){
   build_sieve();
	scanf("%d",&n);	
	while(n){
		count = 0;
		for(i = 0; primes[i] <= n/2 ;i++) if(!sieve[n-primes[i]]) count++;
		printf("%d\n",count);
		scanf("%d",&n);
	}
	return 0;
}
