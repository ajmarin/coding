/////////////////////////////////
// 00948 - Fibonaccimal Base
/////////////////////////////////
#include<cstdio>
unsigned short cnum;
unsigned int fib[40],i,tofib;
char tail, ans[100];
int main(void){
	fib[0] = fib[1] = 1;
	for(i = 2; i < 40; i++) fib[i] = fib[i-1]+fib[i-2];
	scanf("%u\n",&cnum);
	while(cnum--){
		scanf("%u\n",&tofib);
		printf("%u = ",tofib);
		for(i = 1; fib[i] <= tofib; i++);
		tail = 0;
		do {
			i--;
			if(fib[i] <= tofib) tofib -= fib[i], ans[tail++] = '1',i--;
			ans[tail++] = '0';
		} while(tofib);
		if(i==0) tail--;
		else while(--i) ans[tail++] = '0';
		ans[tail] = 0;
		printf("%s (fib)\n",ans);
	}
	return 0;
}
