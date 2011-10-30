#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
const int NN = 512;
int m[NN][NN], matchL[NN], matchR[NN];
int b, n;
bool seen[NN];

bool bpm(int u){
	FOR(v, n) if(m[u][v] && !seen[v]){
		seen[v] = true;
		if(matchR[v] < 0 || bpm(matchR[v])){
			matchR[v] = u;
			matchL[u] = v;
			return true;
		}
	}
	return false;
}
int main(void){
	int c = 0, t; scanf("%d", &t);
	for(int ans = 0; t-- && scanf("%d %d", &b, &n) == 2; ans = 0){
		FOR(i, b){
			matchL[i] = -1;
			FOR(j, n) matchR[j] = -1, scanf("%d", &m[i][j]);
		}
		FOR(i, b){
			FOR(j, n) seen[j] = false;
			ans += bpm(i);
		}
		printf("Case %d: a maximum of %d ", ++c, ans);
		puts("nuts and bolts can be fitted together");
	}
	return 0;
}

