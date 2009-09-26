#include <cstdio>


long long gcd(long long a, long long b) { 
	if(a % b == 0) return b;
	return gcd(b, a % b);
} 
int main(void){
	long long a, b;
	while(scanf("%lld%lld",&a,&b) && a){
		printf("%lld\n",((a*b)/gcd(a,b))%1713371337LL);
	}
	return 0;
}
