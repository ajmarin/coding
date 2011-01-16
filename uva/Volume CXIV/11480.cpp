/////////////////////////////////
// 11480 - Jimmy's Balls
/////////////////////////////////
#include<cstdio>
long long n;
int cnum = 0;
int main(void){
	while(scanf("%lld",&n) && n) 
		if(n%6) printf("Case %d: %lld\n", ++cnum, ((n%6) + 3 * ((n-7)/6)) * ((n-1)/6));
		else printf("Case %d: %lld\n", ++cnum, 3 * ((n-7)/6) * ((n-1)/6) + n-5);
	return 0;
}