#include <cstdio>
#include <ctime>
typedef long long LL;
bool p[501];
const char * x = "PPPPNNPPPNPPNPN";
LL p3[16];
LL gcd(LL a, LL b){ return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b){ return a / gcd(a, b) * b; }
struct frac {
	LL num, den;
	frac(LL _a = 0, LL _b = 0): num(_a), den(_b) {}
	frac operator+(frac f){
		if(!den) return frac(f.num, f.den);
		if(!f.den) return frac(num, den);
		LL nden = lcm(den, f.den);
		return frac(nden / den * num + nden/f.den * f.num, nden);
	}
	frac operator+=(frac f){
		return *this = *this + f;
	}
	frac reduce(){
		LL g = gcd(num, den);
		num = num / g;
		den = den / g;
		return *this;
	}
} acc, curr;
void bt(int jump, int pos, int n2, int d2, int d3){
	++d3;
	n2 += (p[pos] && x[jump] == 'P') || (!p[pos] && x[jump] == 'N');
	if(jump == 14){
		while(n2 && d2) --n2, --d2;
		curr += frac(1LL << n2, p3[d3] * (1LL << d2));
		return;
	}
	if(pos != 1 && pos != 500) ++d2;
	if(pos != 500) bt(jump + 1, pos + 1, n2, d2, d3);
	if(pos != 1) bt(jump + 1, pos - 1, n2, d2, d3);
}
int main(void){
	clock_t start = clock();
	p3[0] = 1;
	for(int i = 1; i < 16; ++i) p3[i] = 3 * p3[i - 1];
	for(int i = 0; i < 501; ++i) p[i] = i > 1;
	for(int i = 4; i < 501; i+=2) p[i] = 0;
	for(int i = 3; i < 23; i += 2)
		if(p[i]) for(int j = i * i, k = 2*i; j < 501; j += k)
			p[j] = 0;
	frac acc = frac();
	for(int i = 1; i <= 500; ++i){
		curr = frac(0, 0);
		bt(0, i, 0, 0, 0);
		(acc += curr.reduce()).reduce();
	}
	acc.den *= 500;
	acc.reduce();
	printf("Time spent: %.3lfs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
	printf("%lld/%lld = %.15lf\n", acc.num, acc.den, acc.num / (double) acc.den);
	return 0;
} 

