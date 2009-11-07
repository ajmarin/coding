/////////////////////////////////
// 10323 - Factorial! You Must be Kidding!!!
/////////////////////////////////
#include<cstdio>
int n;
const char *under = "Underflow!", *over = "Overflow!";
const char *fact[] = {"40320","362880","3628800","39916800","479001600","6227020800"};
int main(void){
	while(scanf("%d\n",&n)!=EOF){
		if(n > 13 || (n < 0 && n&1)) puts(over);
		else if(n < 8) puts(under);
		else puts(fact[n-8]);
	}
	return 0;
}
