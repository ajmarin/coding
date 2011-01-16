/////////////////////////////////
// 00543 - Goldbach's Conjecture
/////////////////////////////////
#include<cstdio>
#define MAX 1000001
int i,j,n, lim = 1001, pos = 0;
int primes[78498];
bool sieve[MAX];
void build_sieve(){
	primes[0] = 2;
	for(i = 3; i < MAX; i+=2) sieve[i] = false;
	for(i = 4; i < MAX; i+=2) sieve[i] = true;
	for(i = 3; i < MAX; i+=2)
		if(!sieve[i]){
			primes[++pos] = i;
			if(i < lim) for(j = i*i; j < MAX; j+=i) sieve[j] = true;
		}
}
int main(void){
	build_sieve();
	//scanf("%d",&n);
	n = 0;
	while(n){
		for(i = 0; sieve[n-primes[i]] ;i++);
		printf("%d = %d + %d\n",n,primes[i],n-primes[i]);
		scanf("%d",&n);
	}
	return 0;
}
	
