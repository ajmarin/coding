#include <cstdio>
#include <map>
#include <string>
#include <vector>
#define MIN(a,b) ((a<b)?(a):(b))
using namespace std;
map< string , int > m;
vector < vector < int > > adj(4000);
string food[4000];
const char *no = "nao", *yes = "sim";
char w1[30], w2[30];
int i, n, nodes;
/* TARJAN {{{ */

int idx[4000], nnnn, low[4000], SCC[4000], stack[4000], scc_count, top;
bool stacked[4000], NO;
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
	for(typeof(adj[k].begin())it = adj[k].begin(); it != adj[k].end(); it++){
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
	adj[a].push_back(b);
	adj[c].push_back(d);
}
void put(){
	string a, nota, b, notb;
	int x, notx, y, noty;
	if(w1[0] == '!') nota = string(w1), a = string(w1+1);
	else a = string(w1), nota = "!"+string(w1);
	if(w2[0] == '!') notb = string(w2), b = string(w2+1);
	else b = string(w2), notb = "!"+string(w2);
	if(m.find(a) == m.end()){
		x = m[a] = nodes++; notx = m[nota] = nodes++;		
		adj[x].clear(); adj[notx].clear();
		idx[x] = idx[notx] = -1;
		SCC[x] = SCC[notx] = stacked[x] = stacked[notx] = 0;
	}
	if(m.find(b) == m.end()){
		y = m[b] = nodes++; noty = m[notb] = nodes++;
		adj[y].clear(); adj[noty].clear();
		idx[y] = idx[noty] = -1;
		SCC[y] = SCC[noty] = stacked[y] = stacked[noty] = 0;
	}
	x = m[a]; y = m[b]; notx = m[nota]; noty = m[notb];
	if(w1[0] == '!'){
		if(w2[0] == '!') insert_edges(x,noty,y,notx);
		else insert_edges(x,y,noty,notx);
	} else {
		if(w2[0] == '!') insert_edges(notx,noty,y,x);
		else insert_edges(notx,y,noty,x);
	}
}
int main(void){
	for(int inst =  1; scanf("%d",&n)==1; inst++){
		m.clear();
		nnnn = nodes = scc_count = top = 0;
		while(n--) scanf("%s %s",&w1,&w2), put();
		for(i = 0; i < nodes; i++)
			if(idx[i] == -1) tarjan(i);
		for(NO = i = 0; i < nodes; i+=2)
			if(SCC[i] && SCC[i] == SCC[i+1]){ NO = 1; break; }
		printf("Instancia %d\n%s\n\n",inst,(NO? no: yes));
	}
	return 0;
}
