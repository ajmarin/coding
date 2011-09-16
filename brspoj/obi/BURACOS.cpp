#include <cstdio>
#include <cstring>
#include <vector>
#define NN 3000
#define MIN(a,b) ((a<b)?(a):(b))
using namespace std;
vector < vector < int > > adj(NN);
/* TARJAN {{{ */
int idx[NN], nnnn, low[NN], SCC[NN], stack[NN], scc_count, top;
bool stacked[NN], NO;
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
	push(k);
	for(typeof(adj[k].begin())it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = (*it);
		if(idx[nadj] == 0){
			tarjan(nadj);
			low[k] = MIN(low[k],low[nadj]);
		} else if(stacked[nadj]) {
			low[k] = MIN(low[k],idx[nadj]);
		}		
	}
	adj[k].clear();
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k)SCC[x = pop()] = scc_count;
	}
}
/* }}} */
int main(void){
	int a, b, i, P, H;
	for(int t = 1; scanf("%d%d",&P,&H) && P; t++){
		printf("Teste %d\n",t);
		memset(idx,0,sizeof(int)*P);
		while(H--)
			scanf("%d%d",&a,&b),
			adj[--a].push_back(--b);
		nnnn = scc_count = top = 0;
		for(i = 0; i < P; i++) if(idx[i] == 0) tarjan(i);
		if(scc_count == 1) puts("S\n");
		else puts("N\n");
	}
	return 0;
}
