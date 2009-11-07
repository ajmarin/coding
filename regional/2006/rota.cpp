#include <cstdio>
#include <string>
#include <map>

#define NN 128
#define MM 10024

using namespace std;

int n, m;
string cidades[NN];
map<string, int> ids;
int w[NN][NN];
int u[MM], v[MM];
int vis[NN];
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
			for(j = 0; j < n; j++)
				w[i][j] = 0;

		/* input */
		for(i = 0; i < n; i++) {
			scanf("%s", bufa), cidades[i] = bufa;
			ids[cidades[i]] = i;
		}
		for(i = 0; i < m; i++) {
			scanf("%s %s", bufa, bufb);
			a = ids[string(bufa)], b = ids[string(bufb)];
			w[a][b]++;
			u[i] = a, v[i] = b;
		}

		/* processa/output */
		bcnt = 0;
		for(i = 0; i < m; i++) {
			w[u[i]][v[i]]--;
			cnt = 0;
			for(j = 0; j < n; j++) vis[j] = 0;
			dfs(0);
			if(cnt < n) {
				printf("%s %s\n", cidades[u[i]].c_str(), cidades[v[i]].c_str());
				bcnt++;
			}
			w[u[i]][v[i]]++;
		}
		if(bcnt == 0) printf("Nenhuma\n");
		printf("\n");
	}

	return 0;
}
