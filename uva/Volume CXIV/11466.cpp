#include <cmath>
#include <cstdio>

const int MAXP = 10000000, ROOT = 3162;
bool prime[MAXP];
int p[MAXP / 8], pc;
long long lpd;
int cnt_div;

void reduce(long long& n, long long div){
	if(n == 1 || n % div) return;
	++cnt_div;
	lpd = div;
	do n /= div; while(!(n % div));
}

int main(void){
	for(int i = pc = 0; i < MAXP; ++i) prime[i] = i & 1;
	prime[2] = true;
	for(int i = 3; i < ROOT; ++i) if(prime[i])
		for(int j = i*i, k = 2*i; j < MAXP; j += k)
			prime[j] = false;
	for(int i = 2; i < MAXP; ++i)
		if(prime[i]) p[pc++] = i;
	for(long long n; scanf("%lld", &n) == 1 && n; ){
		if(n < 0) n = -n;
		cnt_div = 0;
		for(int i = 0; i < pc; ++i){
			reduce(n, p[i]);
			if(p[i] > n / p[i]) break;
		}
		reduce(n, n);
		if(cnt_div > 1) printf("%lld\n", lpd);
		else puts("-1");
	}
	return 0;
}
