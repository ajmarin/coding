#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
struct BigInt {
	char n[32768];
	int sz;
	BigInt(string num = "0"){
		n[sz = num.size()] = 0;
		while(sz--) n[sz] = num[sz];
	}
	BigInt(int b){
		if(b) *this = BigInt("1");
		else *this = BigInt("0");
	}
	BigInt operator +(BigInt& b){
		char *p, *q;
		int c, i, l1 = strlen(n), l2 = strlen(b.n);
		for(i = l1; i < l2; ++i) n[i] = '0'; n[i] = 0;
		for(i = l2; i < l1; ++i) b.n[i] = '0'; b.n[i] = 0;
		for(c = i = 0, p = n, q = b.n; i < l1 || i < l2; ++i){
			*p = (c = *p++ + *q++ - 96 + c) % 10 + '0';
			c /= 10;
		}
		if(c) *p++ = c + '0';
		*p = 0;
		b.n[l2] = 0;
		return *this;
	}
	BigInt operator +=(BigInt& b){
		return *this = *this + b;
	}
};

BigInt ans, dp[2][10];
int main(void){
	for(int base, n; scanf("%d %d", &n, &base) == 2; ){
		for(int i = 0; i < base; ++i) dp[0][i] = i>0;
		for(int i = 1; i < n; ++i)
			for(int j = 0; j < base; ++j){
				strcpy(dp[i&1][j].n, "0");
				for(int k = j == 0; k < base; ++k)
					dp[i&1][j] += dp[1-(i&1)][k];
			}
		strcpy(ans.n, "0");
		for(int i = 0; i < base; ++i) ans += dp[1-(n&1)][i];
		for(int i = strlen(ans.n); i--; putc(ans.n[i], stdout));
		puts("");
	}
	return 0;
}

