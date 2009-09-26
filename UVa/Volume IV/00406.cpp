/////////////////////////////////
// 00406 - Prime Cuts
/////////////////////////////////
#include<cstdio>
#include<cstring>
typedef unsigned short int USI;
USI C,i,idx,j,jidx,key,hmp,primes[193],show,shown;
unsigned char jump[] = {64,32,16,8,4,2,1};
bool sieve[1600];
USI bin_search(){
	for(jidx =0,idx = 128; jidx < 7;jidx++){
		if(primes[idx] > key) idx-=jump[jidx];
		else if(primes[idx] < key) idx+=jump[jidx];
		else break;
	}
	return idx;
}
int main(void){
	memset(sieve,1,sizeof(sieve));
	primes[0] = 1;
	primes[1] = 2;
	for(i=4;i<1600;i+=2) sieve[i] = 0;
	for(idx = 2, i = 3; idx != 193; i+=2)
		if(sieve[i]){
			primes[idx++] = i;
			if(i < 40) for(j = i*i; j < 1600; j+=i) sieve[j] = 0;
		}
	while(scanf("%u %u",&key,&C)==2){
		printf("%u %u:",key,C);
		hmp = bin_search();
		while(primes[hmp] <= key) ++hmp;
		if(hmp&1) show = (C<<1) - 1;
		else show = C<<1;
		if(show > hmp) for(i = 0; i < hmp; printf(" %u",primes[i]),i++);
		else {
			i = (hmp>>1)-(show>>1);		
			shown = 0;
			while(shown!=show) {
				printf(" %u",primes[i++]);
				shown++;
			}
		}
		printf("\n\n");
	}			
	return 0;
}
