#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 10030;
bool l[N];
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){	
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
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
}
vector < int > adj[N];
int idx[N], __idx, low[N], SCC[N], stack[N], scc_count, top;
bool onstack[N], NO;
void push(int a){ stack[top++] = a; onstack[a] = 1;}
int pop(){onstack[stack[--top]] = 0;return stack[top];}
void tarjan(int k){
	idx[k] = low[k] = __idx = __idx+1;
	push(k);
	for(typeof(adj[k].begin()) it = adj[k].begin(); it != adj[k].end(); it++){
		int nadj = *it;
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = min(low[k],low[nadj]);
		} else if(onstack[nadj])low[k] = min(low[k],idx[nadj]);
	}
	if(low[k] == idx[k]){
		int x = -1;
		while(x != k) SCC[x = pop()] = scc_count;
		l[scc_count++] = 1;
	}
}
int main(void){
	int a, b, m, n, t;
	readint(&t);
	for(int cnum = 0; cnum++ < t; ){
		readint(&n); readint(&m);
		scc_count = 0;
		for(int i = 0; i < n; ++i) idx[i] = -1, adj[i].clear();
		for(int i = 0; i < m; ++i){
			readint(&a); readint(&b);
			adj[--a].push_back(--b);
		}
		for(int i = 0; i < n; ++i) if(idx[i] == -1) tarjan(i);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < adj[i].size(); ++j){
				int target = SCC[adj[i][j]];
				if(target == SCC[i]) continue;
				if(l[target]) scc_count--, l[target] = 0;
			}
		printf("Case %d: %d\n", cnum, scc_count);
	}
	return 0;
}
