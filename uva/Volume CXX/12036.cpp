#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)
int cnt[128];

int main(void){
	int t; scanf("%d", &t);
	for(int c = 0, n, z; c++ < t; ){
		bool stable = true;
		FOR(i, 128) cnt[i] = 0;
		scanf("%d", &n);
		FOR(i, n) FOR(j, n){
			scanf("%d", &z);
			stable &= ++cnt[z] <= n;
		}
		printf("Case %d: ", c);
		puts(stable ? "yes" : "no");
	}
	return 0;
}

