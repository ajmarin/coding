#include <cstdio>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		1000000000
#define DIGITS		15
#define LOG10BASE	9
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
		}
		puts("");
	}
	BigInt(int v = 0){ clear(); num[0] = v; carry(); }
	BigInt(BigInt* b){ FOR(i, DIGITS) num[i] = b->num[i]; }
	BigInt operator+(BigInt b){
		BigInt r = this;
		FOR(i, DIGITS) r.num[i] += b.num[i];
		r.carry();
		return r;
	}
	BigInt operator+=(BigInt b){ return *this = *this + b; }
};

char word[10048], key[128];
int main(void){
	BigInt r[128];
	r[0] = 1;
	int t;
	for(scanf("%d", &t); t--; ){
		scanf("%s", word);
		scanf("%s", key + 1);
		int kl = 0;
		while(key[++kl]);
		for(int i = 1; i < kl; ++i) r[i] = 0;
		for(int i = 0; word[i]; ++i)
			for(int j = kl; --j; ) if(word[i] == key[j]) r[j] += r[j - 1];
		r[kl - 1].show();
	}
	return 0;
}

