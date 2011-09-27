#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)

int p[16][2];
int m, n;
bool possible;

void bt(int k, int l, int r, int mask){
	if(possible) return;
	if(k == n-1){
		// find last piece
		FOR(i, m) if(!(mask & (1 << i))){
			possible |= (p[i][0] == l && p[i][1] == r) || (p[i][0] == r && p[i][1] == l);
		}
		return;
	}
	FOR(i, m){
		if(mask & (1 << i)) continue;
		if(p[i][0] == l)
			bt(k + 1, p[i][1], r, mask | (1 << i));
		if(p[i][1] == l)
			bt(k + 1, p[i][0], r, mask | (1 << i));
	}
}

int main(void){
	while(scanf("%d %d", &n, &m) == 2 && (n || m)){
		int l, r;
		scanf("%*d %d %d %*d", &l, &r);
		FOR(i, m) scanf("%d %d", &p[i][0], &p[i][1]);
		possible = false;
		bt(0, l, r, 0);
		puts(possible ? "YES" : "NO");
	}
	return 0;
}

