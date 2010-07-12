/////////////////////////////////
// 00294 - Divisors
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool sieve[31622];
unsigned short int div,i,idx,occ,primes[3401];
unsigned int chosen,cnum,j,maxdiv,u,l;
void factors(unsigned int n){
	div = 1;
	for(i = 0; n != 1 && i < 3401; i++)
		if(!(n%primes[i])){
			occ = 0;
			while(!(n%primes[i])){
				n/=primes[i];
				occ++;
			}
			div*=(occ+1);
		}
	if(n!=1) div*=2;
}
int main(void){
	memset(sieve,1,sizeof(sieve));
	sieve[0] = sieve[1] = 0;
	primes[0] = 2;
	for(i = 4; i < 31622; i+=2) sieve[i] = 0;
	for(idx=1,i = 3; i < 31622; i+=2){
		if(sieve[i]){
			primes[idx++] = i;
			if(i < 177) for(j = i*i; j < 31622; j+=i) sieve[j] = 0;
		}
	}
	scanf("%u",&cnum);
	while(cnum--){
		scanf("%u %u\n",&u,&l);
		maxdiv = 0;
		for(j = u; j <= l; j++){
			factors(j);
			if(div > maxdiv){
				maxdiv = div;
				chosen = j;
			}
		}
		printf("Between %u and %u, %u has a maximum of %u divisors.\n",u,l,chosen,maxdiv);		
	}
	return 0;
}