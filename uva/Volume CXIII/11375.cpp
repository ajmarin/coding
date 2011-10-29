#include <cstdio>

#define FORI(i,s,n) for(int i = s; i < n; ++i)
const int mxs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <string>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		100000000
#define DIGITS		70
#define LOG10BASE	8
struct BigInt {
	int num[DIGITS], last;
	void clear(){ FOR(i, DIGITS) num[i] = 0; }
	void carry(){
		int c = 0;
		FOR(i, last){
			c = (num[i] += c) / BASE;
			num[i] %= BASE;
		}
		while(c){
			num[last++] = c % BASE;
			c /= BASE;
		}
	}
	int upd_last(){ for(last = DIGITS; last > 0 && !num[--last]; ); return ++last; }
	void show(){
		int i = last;
		printf("%d", num[--i]);
		while(i--) printf("%0*d", LOG10BASE, num[i]);
		puts("");
	}
	BigInt(int v = 0){ clear(); num[0] = v; last = 1; carry(); }
	BigInt(BigInt* b){ FOR(i, b->last) num[i] = b->num[i]; }
	BigInt operator+=(const BigInt& b) { 
		last = max(last, b.last);
		FOR(i, last) num[i] += b.num[i];
		carry();
		return *this;
	}
};

BigInt dp[2048];

int main(void){
	FORI(i, 0, 2048) dp[i] = 0;
	dp[2] = dp[3] = dp[4] = dp[7] = 1;
	dp[6] = 2;
	dp[5] = 3;
	FORI(i, 2, 2001){
		FORI(j, 0, 10) dp[i + mxs[j]] += dp[i];
		dp[i] += i == 6;
		dp[i] += dp[i - 1];
	}
	for(int n; scanf("%d", &n) == 1; dp[n].show());
	return 0;
}

