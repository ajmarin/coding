#include<cstdio>
#include<cstring>
#define MAX 1000001
bool sieve[MAX];
unsigned short primes[168];
unsigned int i,j,n,idx;
short facts(register unsigned int k){
	if(sieve[k]) return 1;
	short ret = 0;
	for(i = 0; i < 168; i++){		
		if(!(k%primes[i])){
			ret++;
			while(!(k%primes[i])) k/=primes[i];
			if(k==1) break;
		}
	}
	if(k!=1) ret++;
	return ret;
}
int main(void){
	memset(sieve,1,MAX);
	sieve[0] = sieve[1] = 0;
	primes[0] = 2;
	for(i = 4; i < MAX; i+=2) sieve[i] = 0;
	for(idx =1,i = 3; i < 1000; i+=2)
		if(sieve[i]){
			primes[idx++] = i;
			for(j = i*i; j < MAX; j+=i) sieve[j] = 0;
		}
	while(scanf("%u\n",&n) && n){
		printf("%u : %hu\n",n,facts(n));
	}
	return 0;
}

