#include <cstdio>
int v[32];
int min(int a, int b){ return a < b ? a : b; }
int abs(int a){ return a < 0 ? -a : a; }
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int i, j, md = 1<<29, s, t = 0;
		for(i = 0; i < n; ++i) scanf("%d", v + i), t += v[i];
		for(i = 0; i < (1<<n); ++i){
			for(j = s = 0; j < n; ++j) if(i & (1<<j)) s += v[j];
			md = min(md, abs(t - (s << 1)));
		}
		printf("%d\n", md);
	}
	return 0;
}

