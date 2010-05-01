#include <cstdio>

inline int sq(int x){ return x * x;}
int bigmod(int n, int p, int m){
	if(!p) return 1;
	if(p & 1) return ((n % m) * (bigmod(n, p - 1, m) % m)) % m;
	return sq(bigmod(n, p >> 1, m) % m) % m;
}
int main(void){
	int ans, k, mod, n, nek1, p, sum, t, x;
	scanf("%d", &t);
	for(int cnum = 0; cnum < t; ){
		sum = 0; 
		scanf("%d %d %d", &n, &k, &mod);
		p = n;
		while(p--){
			scanf("%d", &x);
			sum = (sum + (x % mod)) % mod;
		}
		ans = ((bigmod(n, k - 1, mod) * sum) % mod) * (k % mod);
		printf("Case %d: %d\n", ++cnum, ans % mod);
	}
	return 0;
}
