#include <cstdio>
const int N = 10048;
int p[32] = {2, 3, 5, 7, 11, 13, 17, 19,
	23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
	67, 71, 73, 79, 83, 89, 97, 101, 0};
int psq[32], fct[N], sqf[N], sqfc = 0, v[N];
int factors(int k){
	int r = 0;
	for(int i = 0; ; ++i){
		if(!(k % p[i])){
			++r;
			k /= p[i];
		}
		if(p[i] * p[i] > k) break;
	}
	return r + (k != 1);
}
bool f(int k){
	for(int i = 0; p[i] != 101; ++i)
		if(!(k % psq[i])) return 0;
	return 1;
}
long long choose(long long n){
	return n < 4 ? 0 : (n * (n - 1) * (n - 2) * (n - 3)) / 24;
}
int main(void){
	for(int i = 0; p[i] != 101; ++i) psq[i] = p[i] * p[i];
	for(int i = 2; i < 10000; ++i) 
		if(f(i)){
			sqf[sqfc] = i;
			fct[sqfc] = factors(i);
//			printf("%d with %d factors\n", i, fct[sqfc]);
			sqfc++;
		}
	for(int n; scanf("%d", &n) == 1; ){
		long long ans = choose(n);
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		for(int i = 0; i < sqfc; ++i){
			int cnt = 0;
			for(int j = 0; j < n; ++j) cnt += !(v[j] % sqf[i]);
			if(fct[i] & 1) ans -= choose(cnt);
			else ans += choose(cnt);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

