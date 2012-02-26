#include <cstdio>
#include <queue>
using namespace std;

struct edge { int next, to; } e[10048];
int ecnt, next[32], vis[32];

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.next = next[from];
	E.to = to;
	next[from] = ecnt++;
}

int main(void){
	queue < pair<int, int> > q;
	char a, b, c;
	for(int m, n; scanf("%d %d", &n, &m) == 2; ){
		int at, d, v, visited = ecnt = 0;
		for(int i = 0; i < 26; ++i) vis[i] = 0, next[i] = -1;
		scanf(" %c%c%c", &a, &b, &c);
		q.push(make_pair(a - 'A', 0)); vis[a - 'A'] = 3;
		q.push(make_pair(b - 'A', 0)); vis[b - 'A'] = 3;
		q.push(make_pair(c - 'A', 0)); vis[c - 'A'] = 3;
		while(m--){
			scanf(" %c%c", &a, &b);
		//	printf("%c %c\n", a, b);
			add_edge(a - 'A', b - 'A');
			add_edge(b - 'A', a - 'A');
		}
		while(!q.empty()){
			at = q.front().first;
			d = q.front().second;
		//	printf("%c, %d\n", at + 'A', d);
			q.pop();
			++visited;
			for(at = next[at]; at != -1; at = e[at].next)
				if(++vis[v = e[at].to] == 3) q.push(make_pair(v, d + 1));
		}
		if(visited == n) printf("WAKE UP IN, %d, YEARS\n", d);
		else puts("THIS BRAIN NEVER WAKES UP");
	}
	return 0;
}

