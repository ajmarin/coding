#include <cctype>
#include <cstdio>
#include <vector>
using namespace std;

/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */

struct edge {
	int next, to;
	edge(int _next, int _to): next(_next), to(_to) {}
};

int visited;
vector<edge> g;
vector<int> next, vis;

void dfs(int u){
	++visited;
	vis[u] = true;
	for(int at = next[u], v; at != -1; at = g[at].next) if(!vis[v = g[at].to]) dfs(v);
}
int main(void){
	scanf("%*d");
	for(int k, m, n; RI(n) + RI(m) + RI(k) == 3; ){
		g = vector<edge>();
		next = vector<int>(n, -1);
		vis = vector<int>(n, 0);
		visited = 0;
		for(int a, b, cnt = 0; m--; ){
			RI(a), RI(b); --a; --b;
			g.push_back(edge(next[a], b));
			next[a] = cnt++;
		}
		for(int knocked; k--; ) if(RI(knocked) && !vis[--knocked]) dfs(knocked);
		printf("%d\n", visited);
	}
	return 0;
}

