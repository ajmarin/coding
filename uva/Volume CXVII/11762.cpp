#include <cstdio>

#define _PMAX 1048576
#define _SQRT 1024
#define FORS(a, b, c, s)	for(int a = b; a < c; a += s)
#define FORI(a, b, c) 		FORS(a, b, c, 1)
#define FOR(a, b) 			FORS(a, 0, b, 1)

bool sieve[_PMAX], v[_PMAX];
int a[10], f[10], fc, p[_PMAX / 10], pc = 1, tf;
double s[_PMAX];
int primesto(int n){
	int c, u, v;
	for(u = 0, v = pc; u < v; ){
		c = (u + v) >> 1;
		if(p[c] > n) v = c;
		else u = c + 1;
	}
	return u + (p[u] <= n);
}
void factor(int n){
	fc = 0;
	FOR(i, pc){
		int x = p[i];
		if(x * x > n) break;
		if(!(n % x)){
			f[fc] = x;
			a[fc] = 0;
			do{ a[fc]++; n /= x; } while(!(n % x));
			fc++;
		}
	}
	if(n != 1){
		f[fc] = n;
		a[fc++] = 1;
	}
	tf = fc;
}
double doit(int x){
	if(v[x]) return s[x];
	double c = 1 / (double) tf;
	double sum = 0;
	//printf("Entering %d with %d factors\n", x, tf);
	FOR(i, fc){
		if(a[i]){
			if(!(--a[i])) --tf;
			sum += doit(x / f[i]);
			if(!(a[i]++)) ++tf;
		}
	}
	double sl = primesto(x) / (double) tf;
	//printf("Steps to leave %d = %.10lf\n", x, sl);
	s[x] = sl + c * sum;
	//printf("s[%d] = %.10lf\n", x, s[x]);
	v[x] = 1;
	return s[x];
}

int main(void){
	int n, t;
	FOR(i, _PMAX) sieve[i] = 1, v[i] = 0;
	p[0] = 2; v[1] = 1; s[1] = 0;
	FORS(i, 4, _PMAX, 2) sieve[i] = 0;
	FORS(i, 3, _SQRT, 2)
		if(sieve[i]){
			p[pc++] = i;
			FORS(j, i * i, _PMAX, i) sieve[j] = 0;
		}
	FORS(i, _SQRT + ~(_SQRT & 1), _PMAX, 2)
		if(sieve[i]) p[pc++] = i;
	scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		scanf("%d", &n);
		factor(n);
		doit(n);
		printf("Case %d: %.9lf\n", cnum, s[n]);
	}
	return 0;
}
