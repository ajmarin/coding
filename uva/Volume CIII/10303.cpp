#include <algorithm>
#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		10000
#define DIGITS		184
#define LOG10BASE	4
struct BigInt {
	int num[DIGITS];
	void clear(){ FOR(i, DIGITS) num[i] = 0; }
	void carry(){
		int c = 0;
		FOR(i, DIGITS){
			c = (num[i] += c) / BASE;
			num[i] %= BASE;
		}
	}
	int get_last(){ int i; for(i = DIGITS; i-- && !num[i]; ); return i + 1; }
	void show(){
		int i = get_last(), j, k;
		char c[LOG10BASE + 1];
		c[LOG10BASE] = 0;
		printf("%d", num[--i]);
		while(i--){
			for(j = LOG10BASE, k = num[i]; j--; c[j] = k%10 + '0', k /= 10);
			printf("%s", c);
		} puts(""); 
	} 
	BigInt(int v = 0){ clear(); num[0] = v; carry(); }
	BigInt(BigInt* b){ FOR(i, DIGITS) num[i] = b->num[i]; }
	BigInt operator+(BigInt b){
		BigInt r = this;
		FOR(i, DIGITS) r.num[i] += b.num[i];
		r.carry();
		return r;
	}
	BigInt operator*(BigInt b){
		BigInt r;
		int lim_i = get_last(), lim_j = b.get_last();
		FOR(i, lim_i) FOR(j, lim_j) r.num[i+j] += num[i] * b.num[j];
		r.carry();
		return r;
	}
	BigInt operator+=(BigInt b){ return *this = *this + b; }
	BigInt operator*=(BigInt b){ return *this = *this * b; }
};

int mul[1024];
int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int mults = 0;
		for(int k = 2*n; k > n+1; --k) mul[mults++] = k;
		for(int i = 2; i <= n; ++i){
			int x = i;
			for(int j = mults; j--; ){
				int g = gcd(x, mul[j]);
				if(g != 1){
					x /= g;
					mul[j] /= g;
					if(x == 1) break;
				}
			}
		}
		BigInt ans = 1;
		for(int i = 0; i < mults; ++i) ans *= mul[i];
		ans.show();
	}
	return 0;
}

