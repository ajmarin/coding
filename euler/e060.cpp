#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

#define MAX 1000000
#define LIM 1001
#define TOT 78497
bool p[MAX];
int pl[TOT];
int s[5], s_sz;
const int p10[6] = { 1, 10, 100, 1000, 10000, 100000};
bool over = 0;

unsigned int digits(register unsigned  int x){
	register unsigned int l = 0;
	while(x) x /= 10, ++l;
	return l;
}
int concat(int a, int b, int *c, int *d){
	int da = digits(a), db = digits(b);
	*c = a * p10[db] + b;
	*d = b * p10[da] + a;
}
bool prime(int x){
	if(x < MAX) return p[x];
	for(int i = 0; ; ++i){
		int c = pl[i];
		if(c * c > x) return 1;
		if(!(x % c)) return 0;
	}
}
bool go(int h, int idx){
	if(h == 5) return over = 1;
	for(int i = idx + 1; i < 1228; ++i){
		bool ok = 1;
		for(int j = 0; ok && j < h; ++j){
			int ab, ba;
			concat(s[j], pl[i], &ab, &ba);
			ok &= prime(ab) && prime(ba);
		}
		if(ok){
			s[h] = pl[i];
			go(h + 1, i);
			if(over) return 1;
		}
	}
	return 0;
}		
int main(void){
	clock_t ini = clock();
	int ans; bool found;
	/* Erasthotenes' Sieve {{{ */
	int t = 0;
	memset(p, 1, sizeof(p)); p[0] = p[1] = 0;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < LIM; i += 2) if(p[i]){
		pl[t++] = i;
		for(int j = i * i; j < MAX; j += i) p[j] = 0;
	}
	for(int i = LIM; i < MAX; i += 2) pl[t] = i, t += p[i];
	/* }}} */
	for(int a = 0; a < 1228; ++a) {
		s[0] = pl[a];
		if(go(1, a)) break;
	}
	
	ans = s[0] + s[1] + s[2] + s[3] + s[4];
	if(over) {
		for(int i = 0; i < 5; ++i){
			if(i) fputs(" + ", stdout);
			printf("%d", s[i]);
		}
		printf(" = %d\n", ans);
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
