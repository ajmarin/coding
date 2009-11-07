/////////////////////////////////
// 00583 - Prime Factors
/////////////////////////////////
#include<cstdio>
#include<cstring>
typedef unsigned int UI;
UI fidx,i,idx,j,n,prime,primes[5133];
char num[11];
bool sieve[50000],first;
bool isprime(){
	if(n%2==0 && n != 2) return 0;
	for(i = 0; primes[i] < n && i < 5133; i++)
		if(!(n%primes[i])) return 0;
	return 1;
}
void showfactor(UI factor){
	if(first){
		first = 0;
		printf(" %u",factor);
	} else printf(" x %u",factor);
}
void factor(){
	prime = isprime();
	if(!prime){
		while(!(n&1)){ showfactor(2); n>>=1;}
		for(idx = 0; n > 1 && idx < 5133; idx++)
			while(!(n%primes[idx])){
				showfactor(primes[idx]);			 	
			 	n/=primes[idx];
			 }
		if(n > 1) printf(" x %u",n);
	}
	else {
		if(num[0] == '-') printf(" x %u",n);
		else printf(" %u",n);
	}
	putchar('\n');
}
int main(void){
	memset(sieve,1,sizeof(sieve));
	for(idx = 0,i = 3; i < 50000; i+=2)
		if(sieve[i]){
			primes[idx++] = i;
			if(i < 223) for(j = i*i; j < 50000; j+=i) sieve[j] = 0;
		}
	while(gets(num)){
		if(num[0] == '0') break;
		printf("%s =",num);
		fidx = 0; first = 1;
		if(num[0] == '-'){
			sscanf(num+1,"%u",&n);
			printf(" -1");
			first = 0;
		} else sscanf(num,"%u",&n);
		factor();
	}
	return 0;
}
