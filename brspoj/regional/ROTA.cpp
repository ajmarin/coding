#include <cstdio>
#include <cstring>
#include <string>
#include <map>
 
#define NN 128
#define MM 10024
 
using namespace std;
 
int n, m;
char c[NN][32];
map < string, int > ids;
int w[NN][NN];
bool avail[NN][NN];
int u[MM], v[MM];
bool vis[NN];
int cnt, bcnt;
 
void dfs(int no) {
	vis[no] = 1;
	cnt++;
	for(int i = 0; i < n; i++)
		if(!vis[i] && w[i][no])
			dfs(i);
}
 
int main(void) {
	char bufa[32], bufb[32];
	int i, j, a, b;
	 
	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0) break;
		 
		/* init */
		ids.clear();
		for(i = 0; i < n; i++)
			memset(w[i], 0, n << 2);
		 
		/* input */
		for(i = 0; i < n; i++) {
			scanf("%s", c[i]);
			ids[string(c[i])] = i;
		}
		for(i = 0; i < m; i++) {
			scanf("%s %s", bufa, bufb);
			a = ids[string(bufa)], b = ids[string(bufb)];
			w[a][b]++;
			u[i] = a, v[i] = b;
		}
		 
		/* processa/output */
		bcnt = 0;
		int *pu = u, *pv = v;
		for(i = 0; i < m; ++i, ++pu, ++pv) {
			if(w[*pu][*pv] > 1)	continue;
			w[*pu][*pv]--;
			cnt = 0;
			memset(vis, 0, n);
			dfs(0);
			if(cnt < n) {
				printf("%s %s\n", c[*pu], c[*pv]);
				bcnt++;
			}
			w[*pu][*pv]++;
		}
		if(!bcnt) printf("Nenhuma\n");
		putc(10, stdout);
	}
	 
	return 0;
}
