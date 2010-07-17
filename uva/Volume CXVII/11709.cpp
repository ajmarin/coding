#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;
#define FOR(a,b,c) for(int a = b; a < c; ++a)
#define IN getc(stdin)
#define N 1000
map < string, int > m;
char name[32];
int adj[N][N], as[N];
int idx[N], __idx, low[N], SCC[N], stack[N], scc_count, top;
bool onstack[N], NO;
void push(int a){ stack[top++] = a; onstack[a] = 1;}
int pop(){onstack[stack[--top]] = 0;return stack[top];}
void tarjan(int k){
	idx[k] = low[k] = __idx = __idx+1;
	push(k);
	FOR(i, 0, as[k]){
		int nadj = adj[k][i];
		if(idx[nadj] == -1){
			tarjan(nadj);
			low[k] = min(low[k],low[nadj]);
		} else if(onstack[nadj])low[k] = min(low[k],idx[nadj]);
	}
	if(low[k] == idx[k]){
		scc_count++;
		int x = -1;
		while(x != k) SCC[x = pop()] = scc_count;
	}
}
string getname(){
	register char c;
	for(char *n = name; ; n++){
		*n = (c = IN);
		if(*n == 10){ *n = 0; break; }
	}
	return string(name);
}
int main(void){
	int P, T;
	while(scanf("%d %d\n", &P, &T) && P){
		scc_count = 0;
		FOR(i, 0, P) m[getname()] = i, as[i] = 0, idx[i] = -1;
		FOR(i, 0, T){
			int a = m[getname()];	
			adj[a][as[a]++] = m[getname()];
		}
		FOR(i, 0, P) if(idx[i] == -1) __idx = 0, tarjan(i);
		printf("%d\n", scc_count);
	}
	return 0;
}
