#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <string>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		1000
#define DIGITS		1000
#define LOG10BASE	3
int MAX(int a, int b){ return a > b ? a : b; }
struct BigInt {
	int num[DIGITS], last;
	void clear(){ FOR(i, DIGITS) num[i] = 0; }
	void carry(){
		int c = 0;
		last = get_last();
		FOR(i, last){
			c = (num[i] += c) / BASE;
			num[i] %= BASE;
		}
		while(c) num[last++] = c % BASE, c /= BASE;
	}
	int get_last(){ int i; for(i = DIGITS; i > 0 && !num[--i]; ); return i + 1; }
	void show(){
		int i = last;
		printf("%d", num[--i]);
		while(i--) printf("%0*d", LOG10BASE, num[i]);
		puts("");
	}
	BigInt(int v = 0){ clear(); num[0] = v; carry(); }
	BigInt(char *v){
		char *last = v;
		int mult, pos = 0, z;
		clear();
		while(*last) ++last; --last;
		while(last >= v){
			mult = 1; z = 0;
			FOR(i, LOG10BASE){
				z = mult * (*last - '0') + z;
				mult *= 10;
				if(--last < v) break;
			}
			num[pos++] = z;
		}
	}
	BigInt(BigInt* b){ FOR(i, DIGITS) num[i] = b->num[i]; }
	BigInt(string v){ BigInt(v.c_str()); }
	BigInt operator+(const BigInt& b){
		BigInt r = BigInt(0);
		int lim = MAX(last, b.last);
		FOR(i, lim) r.num[i] = num[i] + b.num[i];
		r.carry();
		return r;
	}
	BigInt operator*(const BigInt& b){
		BigInt r = BigInt(0);
		FOR(i, last) FOR(j, b.last) r.num[i+j] += num[i] * b.num[j];
		r.carry();
		return r;
	}
	BigInt operator-(const BigInt& b){
		BigInt r;
		FOR(i, last) r.num[i] += num[i] + BASE - b.num[i] - (i != 0);
		r.carry();
		r.num[--r.last] = 0;
		return r;
	}
	BigInt operator+=(const BigInt& b){ return *this = *this + b; }
	BigInt operator*=(const BigInt& b){ return *this = *this * b; }
	BigInt operator-=(const BigInt& b){ return *this = *this - b; }
	int compare(const BigInt& b){
		int lim_i = last, lim_j = b.last;
		if(lim_i != lim_j) return (lim_i > lim_j) - (lim_i < lim_j);
		for(int x = lim_i; x--; )
			if(num[x] != b.num[x]) return (num[x] > b.num[x]) - (num[x] < b.num[x]);
		return 0;
	}
	bool operator>(const BigInt& b){ return compare(b) == 1; }
	bool operator>=(const BigInt& b){ return compare(b) > -1; }
	bool operator==(const BigInt& b){ return compare(b) == 0; }
	bool operator<(const BigInt& b){ return compare(b) == -1; }
	bool operator<=(const BigInt& b){ return compare(b) < 1; }
	bool operator!=(const BigInt& b){ return compare(b) != 0; }
};

int main(void){
	BigInt r = "12345678987654321";
	assert(r * 7 == "86419752913580247");
	assert(BigInt(69) > BigInt(52));
	assert(BigInt(873) > BigInt(218));
	assert(BigInt(159) < BigInt(951));
	assert(BigInt(5) * BigInt(2) == BigInt(10));
	assert(BigInt(777) * BigInt(3333) == BigInt(2589741));
	assert(BigInt("4611686018427387904") + BigInt("4611686018427387904") == BigInt("9223372036854775808"));
	assert(BigInt("1152921504606846976") + BigInt("1152921504606846976") == "2305843009213693952");
	assert(BigInt("1125899906842624") * BigInt(1<<10) == BigInt("1152921504606846976"));
	assert(BigInt(2) > BigInt("1"));
	assert(BigInt(1<<30) >= BigInt(1<<30));
	assert(BigInt("123456789999999999998") < BigInt("123456789999999999999"));
	assert(BigInt("123456789999999999999") <= BigInt("123456789999999999999"));
	assert(BigInt("1723") < 88884);
	assert(BigInt("123") > 122);
	assert(BigInt(140) >= 140);
	assert(BigInt(130) <= 130);
	printf("TEST SUCEEDED\n");
	return 0;
}
