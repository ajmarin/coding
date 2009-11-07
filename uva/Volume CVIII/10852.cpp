/////////////////////////////////
// 10852 - Less Prime
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool sieve[5005];
unsigned short int i,j;
unsigned int cnum,lim,n;
int main(void){
	memset(sieve,1,sizeof(sieve));
	sieve[0] = sieve[1] = 0;
	for(i = 4; i < 5005; i+=2) sieve[i] = 0;
	for(i = 3; i < 70; i+=2)
		if(sieve[i])
			for(j = i*i; j < 5005; j+=i) sieve[j] = 0;
	scanf("%u",&cnum);
	while(cnum--){
		scanf("%u",&n);
		if(n&1) lim = ((n+1)>>1);
		else lim = ((n+2)>>1);
		if(!(lim&1)) lim++;
		while(!sieve[lim]) lim+=2;
		printf("%u\n",lim);
	}
	return 0;
}
