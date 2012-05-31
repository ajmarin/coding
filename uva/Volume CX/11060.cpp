#include <cstdio>
#include <map>
#include <string>
using namespace std;

char bvg[128][64];
int c, ecnt;
map< string, int > m;
int deg[128], head[128];
int get_index(string s){
	int &z = m[s];
	if(!z) z = ++c;
	return z;
}

struct edge { int to, next; } e[256]; 
void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.to = to;
	E.next = head[from];
	head[from] = ecnt++;
	++deg[to];
}

int main(void){
	for(int cnum = 1, n, z; scanf("%d", &n) == 1 && n; ++cnum){
		c = ecnt = 0;
		m.clear();
		for(int i = 1; i <= n; ++i){
			scanf("%s", bvg[i]);
			get_index(bvg[i]);
		}
		for(int i = 1; i <= n; ++i) deg[i] = 0, head[i] = -1;
		scanf("%d", &z);
		for(int a, b, i = 0; i < z; ++i){
			scanf("%s", bvg[0]);
			a = get_index(bvg[0]);
			scanf("%s", bvg[0]);
			b = get_index(bvg[0]);
			add_edge(a, b);
		}
		printf("Case #%d: Dilbert should drink beverages in this order:", cnum);
		for(int i = 1; i <= n; ++i) if(!deg[i]){
			printf(" %s", bvg[i]);
			--deg[i];
			for(int j = head[i]; j != -1; j = e[j].next) --deg[e[j].to];
			i = 0;
		}
		puts(".\n");
	}
	return 0;
}

