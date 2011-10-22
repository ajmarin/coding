#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int MAXC = 1000000001, N = 1024;
int n, v, z[N];

bool possible(int x){
	int ccap = x, cv = 0;
	FOR(i, n){
		if(ccap < z[i]){
			ccap = x;
			if(++cv == v) return false;
		}
		ccap -= z[i];
	}
	return true;
}

int max(int a, int b){ return a > b ? a : b; }

int main(void){
	while(scanf("%d%d", &n, &v) == 2){
		int min_cap = 0, u, v, w;
		FOR(i, n) scanf("%d", z + i), min_cap = max(min_cap, z[i]);
		for(u = min_cap, v = MAXC; u < v; ){
			w = (u + v) >> 1;
			if(!possible(w)) u = w + 1;
			else v = w;
		}
		printf("%d\n", u);
	}
	return 0;
}

