#include <cstdio>
#include <cstring>

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define NN 32

int adj[NN][NN], max, N;
/* {{{ Tarjan */
int idx[NN], low[NN], s[NN], scc[NN], sccsz[NN];
int nc, sccn, sccs, t;
bool on[NN]; 

void push(int a){ s[t++] = a; on[a] = 1; }
int pop(){ return on[s[--t]] = 0, s[t]; }

void tarjan(int k){
	idx[k] = low[k] = nc = nc+1;
	push(k);
	FOR(i, N)
		if(adj[k][i]){
			if(idx[i] == -1) tarjan(i),	low[k] = MIN(low[k],low[i]);
			else if(on[i]) low[k] = MIN(low[k],idx[i]);
		}
	if(low[k] == idx[k]){
		sccn++; sccs = 0;
		for(int x = -1; x != k; scc[x = pop()] = sccn, sccs++);
		sccsz[sccn] = sccs;
	}
}
/* }}} */
int main(void){
	int a, b, city = 0;
	while(scanf("%d",&N)==1){
		max = 0;
		memset(adj, 0, sizeof(adj));
		FOR(i, N){
			scanf("%d %d",&a,&b);
			adj[a][b] = 1;
			if(a > max) max = a;
			if(b > max) max = b;
		}
		N = max + 1;
		FOR(i, N) idx[i] = -1, scc[i] = on[i] = 0;
		nc = sccn = t = 0;
		FOR(i, N) if(idx[i] == -1) tarjan(i);
		FOR(i, N) FOR(j, i)
			if(scc[i] == scc[j] && sccsz[scc[i]] > 1)
					adj[i][j] = adj[j][i] = -1;
		FOR(k, N) FOR(i, N) FOR(j, N)
			if((adj[i][k] == -1 && adj[k][j]) || (adj[i][k] && adj[k][j] == -1))
				adj[i][j] = -1;
			else adj[i][j] += adj[i][k]*adj[k][j];
		printf("matrix for city %d\n",city++);
		FOR(i, N){
			FOR(j, N){
				if(j) putc(' ', stdout);
				printf("%d",adj[i][j]);
			}
			putc(10, stdout);
		}
	}
	return 0;
}

