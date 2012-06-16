#include <cmath>
#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
int sqr(int x){ return x * x; }

const int NN = 5555;
int x[NN], y[NN], z[NN];
bool found;

int main(void){
	int cnt[16], n;

	for(n = 0; scanf("%d %d %d", x + n, y + n, z + n) == 3 && (x[n]|y[n]|z[n]); ++n);

	for(int i = 0; i < 16; ++i) cnt[i] = 0;
	int minD, d;
	FOR(i, n){
		minD = 101;
		FOR(j, n) if(i != j){
			d = sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]);
			if(d < minD) minD = d;
		}
		++cnt[int(floor(sqrt(minD)))];
	}
	FOR(i, 10) printf("%4d", cnt[i]);
	puts("");
	return 0;
}

