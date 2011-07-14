#include <cstdio>
typedef long long LL;
LL gcd(LL a, LL b){ return a ? gcd(b % a, a) : b; }
struct frac {
	LL num, den;
	void show(){
		if(den != 1) printf("%lld/%lld\n", num, den);
		else printf("%lld\n", num);
	}
	void simpler(){
		int g = gcd(num, den);
		num /= g; den /= g;
	}
};
int main(void){
	int t; scanf("%d", &t);
	long long n;
	for(int c = 1; t-- && scanf("%lld", &n); ++c){
		printf("Case %d: ", c);
		frac f = {n*(n - 1), 4};
		f.simpler();
		f.show();
	}
	
}
