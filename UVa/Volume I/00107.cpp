/////////////////////////////////
// 00107 - The Cat in the Hat
/////////////////////////////////
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define MAX 45000
unsigned int A,B,height,i,j,k,lim,lazycats,N,T,weight;
unsigned short int idx,occ,primes[5000],countA[9],countB[9],factA[9],factB[9],countAidx,countBidx;
unsigned char gcdT[32][32];
bool sieve[MAX];
unsigned int powi(unsigned int b, unsigned int e){
	unsigned int res = 1;
	for(j = 0; j < e; j++) res*=b;
	return res;
}
unsigned char gcd(unsigned char n, unsigned char m)
{
	if(!m) return n;
	return gcd(m, n%m);
}
void findNandK(){
	countAidx = countBidx = 1;
	for(T = B,i = 0; T != 1; i++)
		if(!(T%primes[i])){
			countB[countBidx] = 0;
			while(!(T%primes[i])){
				T/=primes[i];
				countB[countBidx]++;
			}
			factB[countBidx++] = primes[i];
		}
	if(countBidx-1){ 
		for(T = A,i = 0; T != 1; i++)
			if(!(T%primes[i])){
				countA[countAidx] = 0;
				while(!(T%primes[i])){
					T/=primes[i];
					countA[countAidx]++;
				}
				factA[countAidx++] = primes[i];
			}	
		k = countA[1];
		for(i = countAidx-1; i; i--) k = gcdT[k][countA[i]];
		for(i = countBidx-1; i; i--) k = gcdT[k][countB[i]];
	}
	N = 1;
	for(i = countBidx-1; i; i--) N *= powi(factB[i], countB[i] / k);
}
int main(void){
	memset(sieve,1,MAX);
	sieve[0] = sieve[1] = 0;
	primes[0] = 2;
	lim = (unsigned int)(sqrt(MAX));
	for(i = 4; i < MAX; i+=2) sieve[i] = 0;
	for(idx=1,i = 3; i < MAX; i+=2){
		if(sieve[i]){
			primes[idx++] = i;
			if(i < lim) for(j = i*i; j < MAX; j+=i) sieve[j] = 0;
		}
	}
	for(i = 1; i < 32; i++)
		for(j = i; j < 32; j++)
			if(i == j) gcdT[i][j] = gcdT[j][i] = i;
			else if(sieve[j]) gcdT[i][j] = gcdT[j][i] = 1;
			else gcdT[i][j] = gcdT[j][i] = gcd(j,i);
	while(scanf("%u %u\n",&A,&B) && A && B){
		findNandK(); // (N+1)^k = A ; N^k = B
		lazycats = 0;
		height = A;
		weight = N;
		while(A!=1){
			A/=(N+1);
			height += A*weight;
			B/=N;
			lazycats += B;
			weight *= N;
		}
		printf("%u %u\n",lazycats,height);			
	}
	return 0;
}