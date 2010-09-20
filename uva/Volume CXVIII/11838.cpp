#include <cstdio>
#include <vector>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define NN 2000
vector < int > adj[NN];
int idx[NN], nnnn, low[NN], SCC[NN], s[NN], scc_count, top;
bool ins[NN], NO;
void push(int a){
	s[top++] = a;
	ins[a] = 1;
}
int pop(){
	ins[s[--top]] = 0;
	return s[top];
}
void tarjan(int k){
	idx[k] = low[k] = nnnn = nnnn+1;
	push(k);
	for(typeof(adj[k].begin())it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = (*it);
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = MIN(low[k],low[nadj]);
		} else if(ins[nadj]) {
			low[k] = MIN(low[k],idx[nadj]);
		}		
	}
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k) SCC[x = pop()] = scc_count; 
	}
}
int main(void){
	int a, b, c, m, n;
	while(scanf("%d %d", &n, &m) && n){
		for(int i = 0; i < n; ++i) adj[i].clear(), idx[i] = -1;
		for(int i = 0; i < m; ++i){
			scanf("%d %d %d", &a, &b, &c);
			--a, --b, --c;
			adj[a].push_back(b);
			if(c) adj[b].push_back(a);
		}
		scc_count = nnnn = top = 0;
		tarjan(0);
		printf("%d\n", scc_count < 2 && nnnn == n);
	}
	return 0;
}

