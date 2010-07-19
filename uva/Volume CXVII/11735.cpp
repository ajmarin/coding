#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;
const int N = 1000005;
bool used[N];
int x[N], y[N];
int c, x1, x2, y1, y2;
int find(int k, int *z){
	int u, v;
	for(u = 0, v = c; u < v; ){
		int m = (u + v) >> 1;
		if(z[m] > k) v = m;
		else if(z[m] < k) u = m + 1;
		else return m;
	}
	return u;
}
void correct(int *k, int t, int *v, bool bigger){
	if(bigger){
		while(v[*k] < t) ++*k;
		while(*k && v[*k - 1] >= t) --*k;
	} else {
		while(v[*k] > t) --*k;
		while(*k < c && v[*k + 1] <= t) ++*k;
	}
}
double total = 0;
int p(int *v1, int *v2){
	int ih1, ih2, il1, il2, h, l;
	ih1 = find(x1, v1); ih2 = find(y1, v2);
	correct(&ih1, x1, v1, 1); correct(&ih2, y1, v2, 1);
	il1 = find(x2, v1); il2 = find(y2, v2);
	correct(&il1, x2, v1, 0); correct(&il2, y2, v2, 0);
	h = max(ih1, ih2); l = min(il1, il2);
	return max(l - h + 1, 0);
}
long long gcd(long long a, long long b) { 
	if(a % b == 0) return b;
	return gcd(b, a % b);
} 
int main(void){
	clock_t ini = clock();
	int inc, xx = 0, yy = 0;
	int t, v, v1, v2;
	long long d, g, n;
	x[0] = y[0] = 0;
	for(c = 0; xx <= 1000005; ++c){
		used[xx++] = 1;
		inc = 1 + used[yy + 1];
		yy += inc;
		xx += inc;
		x[c] = xx; y[c] = yy;
	}
	x[c] = 1500000; y[c] = 1500000;
	scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		d = (long long)(y2 - y1 + 1) * (x2 - x1 + 1);		
		v1 = p(x, y);
		v2 = p(y, x);
		v = v1 + v2;
		n = d - v;
		g = gcd(n, d);
		n /= g; d /= g;
		printf("Board %d: %lld / %lld\n", cnum, n, d);
	}
	return 0;
}
