#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct edge { int next, to; } e[1024];
int cost[32], head[32], in[32], in_cost[32], q[32];
char from[32], line[1024], to[32];
int ecnt;

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.next = head[from];
	E.to = to;
	head[from] = ecnt++;
}

int main(void){
	int cn; scanf("%d", &cn); getchar();
	gets(line);
	while(cn--){
		int ans = ecnt = 0, h = 0, t = 0;
		for(int i = 0; i < 32; ++i){
			cost[i] = in[i] = in_cost[i] = 0;
			head[i] = -1;
		}
		while(gets(line) && *line){
			int L = strlen(line), w;
			line[L] = ' ';
			line[L + 1] = '_';
			line[L + 2] = 0;
			sscanf(line, "%s %d %s", to, &w, from);
			cost[*to - 'A'] = w;
			for(int i = 0; from[i] && from[i] != '_'; ++i){
				add_edge(from[i] - 'A', *to - 'A');
				++in[*to - 'A'];
			}
		}
		for(int i = 0; i < 32; ++i) if(!in[i]) q[t++] = i;
		while(h != t){
			int u = q[h++], v;
			ans = max(ans, cost[u] += in_cost[u]);
			for(int at = head[u]; at != -1; at = e[at].next){
				v = e[at].to;
				in_cost[v] = max(in_cost[v], cost[u]);
				if(!--in[v]) q[t++] = v;
			}
		}
		printf("%d\n", ans);
		if(cn) puts("");
	}
	return 0;
}

