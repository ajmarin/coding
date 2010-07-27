#include <cctype>
#include <cstdio>
const int N = 1024;
struct edge {
	int to, w;
} adj[N][N];
int d[N], deg[N];
int idx[N], __idx, low[N], q[N], scc[N], stack[N], scc_count, top;
bool sccan[N], cs[N], onstack[N], onq[N], nothing;
void push(int a){ stack[top++] = a; onstack[a] = 1;}
int pop(){ onstack[stack[--top]] = 0;return stack[top];}
int min(int a, int b){ return a < b ? a : b; }
void tarjan(int k){
	idx[k] = low[k] = __idx = __idx+1;
	push(k);
	for(int i = 0; i < deg[k]; ++i){
		int nadj = adj[k][i].to;
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = min(low[k],low[nadj]);
		} else if(onstack[nadj]) low[k] = min(low[k],idx[nadj]);
		cs[k] |= cs[nadj];
	}
	if(low[k] == idx[k]){
		int sccs = 0, x = -1;
		while(x != k){
			q[sccs++] = x = pop();
			onq[x] = 1;
			d[x] = 0x0FFFFFFF;
			scc[x] = scc_count;
		}
		d[k] = 0;
		for(int i = 0; i < sccs -1; ++i)
			for(int j = 0; j < sccs; ++j){
				x = q[j];
				for(int m = 0; m < deg[x]; ++m){
					int n = adj[x][m].to;
					if(onq[n]){
						int dist = d[x] + adj[x][m].w;
						if(dist < d[n])	d[n] = dist;
					}
				}
			}
		bool neg_cycle = 0;
		for(int j = 0; !neg_cycle && j < sccs; ++j){
			x = q[j];
			for(int m = 0; !neg_cycle && m < deg[x]; ++m){
				int n = adj[x][m].to;
				if(onq[n]){
					int dist = d[x] + adj[x][m].w;
					neg_cycle |= (dist < d[n]);
				}
			}
		}
		for(int i = 0; i < sccs; ++i){
			onq[q[i]] = 0;
			cs[q[i]] |= neg_cycle;
			sccan[scc_count] |= cs[q[i]];
		}
		scc_count++;
	}
}
void dfs(int k){
	idx[k] = 0;
	for(int i = 0; i < deg[k]; ++i){
		int x = adj[k][i].to;
		if(idx[x] == -1) dfs(x);
		cs[k] |= cs[x];
		sccan[scc[k]] |= cs[k];
	}
}
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){
	bool sign = 0;
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	*n = 0;	
	if(now > buf && *(now - 1) == '-') sign = 1;
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
	if(sign) *n *= -1;
}
int main(void){
	int a, b, c, m, n, t;
	readint(&t);
	for(int cnum = 0; cnum++ < t; ){
		readint(&n); readint(&m);
		for(int i = 0; i < n; ++i) sccan[i] = cs[i] = deg[i] = 0, scc[i] = idx[i] = -1;
		for(int i = 0; i < m; ++i){
			readint(&a); readint(&b); readint(&c);
			adj[a][deg[a]].to = b;
			adj[a][deg[a]].w = c;
			deg[a]++;
		}
		printf("Case %d:", cnum);
		nothing = 1;
		scc_count = __idx = 0;
		for(int i = 0; i < n; ++i){
			top = 0;
			if(deg[i] && idx[i] == -1) tarjan(i);			
		}
		for(int i = 0; i < n; ++i) idx[i] = -1;
		for(int i = 0; i < n; ++i){
			if(idx[i] == -1) dfs(i);
			if(cs[i] | (scc[i] != -1 && sccan[scc[i]])) nothing = 0, printf(" %d", i);
		}
		if(nothing) printf(" impossible\n");
		else printf("\n");
	}
	return 0;
}
