/////////////////////////////////
// 10931 - Parity
/////////////////////////////////
#include<cstdio>
unsigned int n;
char ans[35],i,par;
int main(void){
	ans[34] = 0;
	while(scanf("%u",&n) && n){
		i = 33; par = 0;
		do {
			ans[i--] = (n&1)+'0'; par += n&1; n>>=1;
		} while(n);
		printf("The parity of %s is %u (mod 2).\n",ans+i+1,par);
	}
	return 0;
}

