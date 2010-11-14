#include <cstdio>

int r, w[100000];

int nod(int x){
	int d = 1, e;
	while(!(x & 1)) ++d, x >>= 1;
	for(int k = 3; k * k <= x; k += 2){
		if(x % k) continue;
		e = 0;
		while(!(x % k)) ++e, x /= k;
		d *= (e + 1);
	}
	d <<= x != 1;
	return d;
}
int bin_search(int x){
	int mid, u, v;
	for(u = 0, v = r; u < v; ){
		mid = (u + v) >> 1;
		if(w[mid] < x) u = mid + 1; else v = mid;
	}
	return u;
}
int main(void){
	int t;
	w[0] = 1;
	for(r = 1; ; r++) if((w[r] = w[r - 1] + nod(w[r - 1])) > 1000000) break;
	++r;
	scanf("%d", &t);
	for(int a, b, c = 0, lp, rp; c++ < t; ){
		scanf("%d %d", &a, &b);
		lp = bin_search(a);
		rp = bin_search(b);
		rp += w[rp] == b;
		printf("Case %d: %d\n", c, rp - lp);
	}
	return 0;
}
