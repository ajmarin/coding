#include <cstdio>

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define NN 128
int adj[NN][NN], c[NN], deg[NN], s[NN], v[NN];
bool canbe[NN];
int maxblack, n, vis;

void bt(int k, int cnt){
	if(k == n){
		if(cnt > maxblack){
			maxblack = cnt;
			FOR(i, n) s[i] = c[i];
		}
		return;
	}
	if((n - k) + cnt <= maxblack) return;
	if(canbe[k]){
		c[k] = 1;
		int saved[NN];
		FOR(i, deg[k]){
			int x = adj[k][i];
			saved[x] = canbe[x];
			canbe[x] = 0;
		}
		bt(k + 1, cnt + 1);
		FOR(i, deg[k]){
			int x = adj[k][i];
			canbe[x] = saved[x];
		}
	}
	c[k] = 0;
	bt(k + 1, cnt);
}

int main(void){
	int a, b, cnt, k, m; scanf("%d", &m);
	while(m--){
		maxblack = cnt = 0;
		scanf("%d %d", &n, &k);
		FOR(i, n) deg[i] = v[i] = 0, canbe[i] = 1;
		while(k--){
			scanf("%d %d", &a, &b);
			adj[--a][deg[a]++] = --b;
			adj[b][deg[b]++] = a;
		}
		bt(0, 0);
		printf("%d\n", maxblack);
		FOR(i, n){
			if(s[i] && cnt) putc(32, stdout);
			if(s[i]) printf("%d", i + 1), cnt++;
		}
		putc(10, stdout);

	}
	return 0;
}

