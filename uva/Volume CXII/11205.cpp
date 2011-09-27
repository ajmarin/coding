#include <cstdio>

bool seen[1<<16];

int min(int a, int b){ return a < b ? a : b; }
int cnt(int x){ int r; for(r = 0; x; x >>= 1) r += x & 1; return r; }

int v[128];

int main(void){
	int t; scanf("%d", &t);
	for(int i = 0; i < 65536; ++i) seen[i] = false;
	for(int p, n; scanf("%d %d", &p, &n) == 2; ){
		int ans = p, lim = 1 << p;
		for(int i = 0; i < n; ++i){
			int value = 0, z;
			for(int j = 0; j < p; ++j){
				scanf("%d", &z);
				value = (value << 1) + z;
			}
			v[i] = value;
		}

		for(int i = 0, j; i < lim; ++i){
			bool found = true;
			for(j = 0; found && j < n; ++j){
				found &= !seen[v[j] & i];
				seen[v[j] & i] = true;
			}
			if(found) ans = min(ans, cnt(i));
			for(; j--; seen[v[j] & i] = false);
		}
		printf("%d\n", ans);
	}
	return 0;
}

