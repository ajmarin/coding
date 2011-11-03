#include <cstdio>


#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		100000
#define DIGITS		400
#define LOG10BASE	5
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
	BigInt operator+=(BigInt b){ return *this = *this + b; }
	BigInt operator*=(BigInt b){ return *this = *this * b; }
	BigInt operator-=(BigInt b){ return *this = *this - b; }
};

int main(void){
	BigInt ans[801];
	ans[1] = 0;
	BigInt one = BigInt(1);
	for(int i = 2; i < 801; ++i){
		ans[i] = ans[i - 1] * BigInt(i);
		if(i & 1) ans[i] -= one;
		else ans[i] += one;
	}
	for(int n; scanf("%d", &n) == 1 && n != -1; ans[n].show());
	return 0;
}

