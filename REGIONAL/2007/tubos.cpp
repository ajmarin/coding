#include <cstdio>

#define NN 1024

int w[NN][NN];
bool v[NN];
int m, n;
bool tem_ponte;

/* Bridge {{{ */
int cnt, lbl[NN], low[NN], parnt[NN];

void bridgeR(int v) {
	int x;

	low[v] = lbl[v] = cnt++;

	for(x = 1; x <= n && !tem_ponte; x++) {
		if(!w[v][x]) continue;
		if(lbl[x] == -1) {
			parnt[x] = v;
			bridgeR(x);
			if(low[v] > low[x]) low[v] = low[x];
			if(low[x] == lbl[x]) tem_ponte = true;
		} else if(x != parnt[v] && low[v] > lbl[x]) low[v] = lbl[x];
	}
}

void all_bridges() {
	int v;

	cnt = 0;
	tem_ponte = false;

	for(v = 1; v <= n; v++) lbl[v] = -1;
	for(v = 1; v <= n && !tem_ponte; v++)
		if(lbl[v] == -1) bridgeR(parnt[v] = v);
}
/* }}} */

int main(void) {
	int i, j, k;

	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0)
			break;
	
		/* init */
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				w[i][j] = 0;
		
		/* input */
		for(i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			w[a][b] = w[b][a] = 1;
		}
		
		/* processa */
		all_bridges();

		/* output */
		printf("%c\n", (tem_ponte ? 'N' : 'S'));
	}

	return 0;
}
