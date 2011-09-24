#include <cstdio>
#include <map>
#include <string>
using namespace std;
#define FOR(i,n)	for(int i = 1; i <= n; ++i)
const int NN = 64;
char n1[1048576], n2[1048576];
map <string, int> m;
int cnt, p;
int adj[NN][NN], d[NN], q[NN], v[NN];

int index(const char *name){
	int &x = m[name];
	if(!x) x = ++cnt;
	return x;
}

int bfs(int x){
	int head = 0, tail = 0, visited = 0;
	int r = -1;
	FOR(i, p) v[i] = 0;
	q[tail++] = x; d[x] = 0; v[x] = 1;
	while(head != tail){
		int at = q[head++], depth = r = d[at];
		++visited;
		FOR(i, p) if(!v[i] && adj[at][i])
			q[tail++] = i, d[i] = depth + 1, v[i] = 1;
	}
	return visited == p ? r : 0x3f3f3f3f;
}

int main(void){
	for(int net = 1, r; scanf("%d %d", &p, &r) == 2 && (p || r); ++net){		
		m.clear();
		cnt = 0;
		FOR(i, p) FOR(j, p) adj[i][j] = 0;
		for(int a, b, i = 0; i < r; ++i){
			scanf("%s %s", n1, n2);
			a = index(n1);
			b = index(n2);
			adj[a][b] = adj[b][a] = 1;
		}
		int maxd = -1;
		for(int i = 1; i <= p; ++i){
			maxd = max(maxd, bfs(i));
			if(maxd == 0x3f3f3f3f) break;
		}
		printf("Network %d: ", net);
		if(maxd == 0x3f3f3f3f) puts("DISCONNECTED\n");
		else printf("%d\n\n", maxd);
	}
	return 0;
}

