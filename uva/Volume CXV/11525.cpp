#include <cstdio>

const int MAXN = 1 << 16;
int bit[MAXN+1];

void inc(int x, int d){ for(; x <= MAXN; bit[x] += d, x += (x & -x)); }
int read(int x){ int r; for(r = 0; x; r += bit[x], x -= (x & -x)); return r; }
int main(void){
	int K, T;
	for(int i = 1; i <= MAXN; ++i) bit[i] = 0;
	for(scanf("%d", &T); T-- && scanf("%d", &K); ){
		for(int i = 1; i <= K; ++i) inc(i, 1);
		for(int i = 0, z; i < K; ++i){
			scanf("%d", &z); ++z;
			int m, u, v;
			for(u = 1, v = K + 1; u < v; ){
				m = (u + v) >> 1;
				if(read(m) < z) u = m + 1;
				else v = m;
			}
			printf("%d%c", u, i == K - 1 ? '\n' : ' ');
			inc(u, -1);
		}
	}
	return 0;
}

