#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
#define BASE		100000000
#define DIGITS		50
#define LOG10BASE	8
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
	BigInt(BigInt* b){ clear(); FOR(i, b->last) num[i] = b->num[i]; last = b->last;}
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
	BigInt div2(){
		BigInt r = BigInt(this);
		int c = 0;
		for(int lim = r.last; lim--; ){
			c = c * BASE + r.num[lim];
			r.num[lim] = (c >> 1);
			c &= 1;
		}
		while(r.last-- && !num[r.last]);
		return r;
	}
};

int main(void){
	BigInt p2 = BigInt(1), p1 = BigInt(1), p, t = BigInt(2);
	BigInt ans[1501];
	ans[0] = BigInt(0);
	ans[1] = BigInt(1);
	for(int i = 2; i < 1501; ++i){
		p = p1 + p2;
		p2 = p1;
		p1 = p;
		ans[i] = t + (p - 1).div2();
		t += p;
	}
	for(int n, set = 1; scanf("%d", &n) == 1 && n; ++set){
		printf("Set %d:\n", set);
		ans[n - 1].show();
	}

	return 0;
}

