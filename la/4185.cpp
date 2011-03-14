#include <cstdio>
#include <vector>
#define MIN(a,b) ((a<b)?(a):(b))
using namespace std;
const int N = 2048;
vector < int > adj[N];
int a, b, i, m, n;
/* TARJAN {{{ */

int idx[N], nnnn, low[N], SCC[N], stack[N], scc_count, top;
bool stacked[N], seen[N];
void push(int a){
	stack[top++] = a;
	stacked[a] = 1;
}
int pop(){
	stacked[stack[--top]] = 0;
	return stack[top];
}
void tarjan(int k){
	
	idx[k] = low[k] = nnnn = nnnn+1;
	stack[top++] = k;
	stacked[k] = 1;
	vector < int > :: iterator it;
	for(it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = (*it);
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = MIN(low[k],low[nadj]);
		} else if(stacked[nadj]) {
			low[k] = MIN(low[k],idx[nadj]);
		}		
	}
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k)SCC[x = pop()] = scc_count;
	}
}

/* }}} */
void insert_edges(int a, int b, int c, int d){
	adj[a].push_back(b); //printf("Edge (%d -> %d)\n", a, b);
	adj[c].push_back(d); //printf("Edge (%d -> %d)\n", c, d);
}
void read_put(){
	int a, b, nota, notb;
	scanf("%d %d", &a, &b);
#ifdef DBGPUT
	printf("(%d, %d) -> ", a, b);
#endif
	if(a < 0) a = -a - 1; else a += 999;
	if(b < 0) b = -b - 1; else b += 999;
#ifdef DBGPUT
	printf("(%d, %d)\n", a, b);
#endif
	if(a < 1000) nota = a + 1000; else nota = a - 1000;
	if(b < 1000) notb = b + 1000; else notb = b - 1000;
	seen[a] = seen[nota] = seen[b] = seen[notb] = 1;
	insert_edges(nota, b, notb, a);
}
int main(void){
	while(scanf("%d %d", &n, &m) == 2){
		for(i = 0; i < n; ++i){
			seen[i] = seen[i + 1000] = 0;
			idx[i] = idx[i + 1000] = -1;
			SCC[i] = SCC[i + 1000] = stacked[i] = stacked[i + 1000] = 0;
			adj[i].clear();
			adj[i + 1000].clear();
		}
		for(i = 0; i < m; ++i) read_put();
		nnnn = scc_count = top = 0;
		for(i = 0; i < n; i++){
			if(seen[i] && idx[i] == -1) tarjan(i);
			if(seen[i + 1000] && idx[i + 1000] == -1) tarjan(i + 1000);
		}
		int OK = 1;
		for(i = 0; OK && i < n; i++)
			OK &= !(SCC[i] && SCC[i] == SCC[i + 1000]);
		printf("%d\n", OK);
	}
	return 0;
}

