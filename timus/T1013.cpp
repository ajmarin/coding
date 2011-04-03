#include <cstdio>
#include <string>
using namespace std;
const int DIGITS = 2048;
struct BigInt {
	int d[DIGITS], i;
	BigInt(string s = "0"){
		int sz = s.size();
		clear();
		for(i = 0; sz--; ++i) d[i] = s[sz];
	}
	BigInt(int x = 0){
		clear();
		if((d[0] = x) > 9) carry();
	}
	BigInt operator+(BigInt x){
		BigInt z = *this;
		for(i = DIGITS; i--; ) z.d[i] += x.d[i];
		z.carry();
		return z;
	}
	BigInt operator+=(BigInt x){ return *this = *this + x; }
	BigInt operator*(int x){
		BigInt z = *this;
		for(i = DIGITS; i--; ) z.d[i] *= x;
		z.carry();
		return z;
	}
	BigInt operator*=(int x){ return *this = *this * x; }
	void clear(){ for(i = DIGITS; i--; d[i] = 0); }
	void carry(){
		int q, x;
		for(i = q = x = 0; i < DIGITS; ++i){
			x = q + d[i];
			q = x / 10;
			d[i] = x % 10;
		}
	}
	void show(){
		for(i = DIGITS; i--; ) if(d[i] != 0) break;
		while(i >= 0) putc(d[i--] + '0', stdout);
		putc(10, stdout);
	}
};

int main(void){
	for(int i, n, k; scanf("%d %d", &n, &k) == 2; ){
		BigInt a = 1, b = --k, r = 0;
		for(i = 2; i <= n; ++i, a = b, b = r) r = (a + b) * k;
		r.show();
	}
	return 0;
}

