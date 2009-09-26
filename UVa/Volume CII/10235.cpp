/////////////////////////////////
// 10235 - Simply Emirp
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1000001
bool sieve[MAX];
unsigned int i,j,n;
unsigned int revert(unsigned int k){
	unsigned int ret = 0;
	while(k){
		ret*=10; ret+=k%10;
		k/=10;
	}
	if(ret != n) return ret;
	return 33;
}
int main(void){
	memset(sieve,1,sizeof(sieve));
	for(i = 4; i < MAX; i+=2) sieve[i] = 0;
	for(i = 3; i != 1001; i+=2)
		if(sieve[i])
			for(j = i*i; j < MAX; j+=i) sieve[j] = 0;
	while(scanf("%u",&n)!=EOF){
		if(sieve[n]){
			if(sieve[revert(n)]) printf("%u is emirp.\n",n);
			else printf("%u is prime.\n",n);
		} else printf("%u is not prime.\n",n);
	}
	return 0;
}
	
