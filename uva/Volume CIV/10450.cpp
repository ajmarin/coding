/////////////////////////////////
// 10450 - World Cup Noise
/////////////////////////////////
#include<cstdio>
long long int fib[52];
unsigned char i;
unsigned int cnum,tnum;
int main(void){
	fib[0] = fib[1] = 1;
	for(i = 2; i != 52; i++)
		fib[i] = fib[i-1]+fib[i-2];
	scanf("%u",&cnum);
	while(cnum--){
		tnum++;
		scanf("%u\n",&i);
		printf("Scenario #%u:\n%llu\n\n",tnum,fib[i+1]);
	}
	return 0;
}
	
