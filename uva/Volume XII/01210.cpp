#include <cstdio>

const int MAXP = 10500, ROOT = 103;
bool p[MAXP];
int primes[2048], pcnt = 0;
int main(void){
	for(int i = 0; i < MAXP; ++i) p[i] = i > 1;
	for(int i = 4; i < MAXP; i+=2) p[i] = false;
	for(int i = 3; i < ROOT; i += 2){
		if(p[i]) for(int j = i*i, k = 2*i; j < MAXP; j += k) p[j] = false;
	}
	for(int i = 0; i < MAXP; ++i) if(p[i]) primes[pcnt++] = i;

	for(int n; scanf("%d", &n) == 1 && n; ){
		int ans = 0;
		for(int i = 0, j = 0, s = 0; primes[j] <= n; ){
			while(primes[j] <= n && s < n) s += primes[j++];
			while(s > n) s -= primes[i++];
			ans += s == n;
			if(s == n) s -= primes[i++];
		}
		printf("%d\n", ans);
	}
	return 0;
}

