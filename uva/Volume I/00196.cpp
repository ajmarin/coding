#include <cstdlib>
#include <cstdio>
#include <cstring>

#define FOR(i,n) for(int i = 1; i <= n; ++i)
const int NN = 1048576;
struct edge {
	int from, next, to;
} e[NN];
char expr[NN];

int dep[NN], next[NN], q[NN], v[NN];
int edges;

void add_edge(int from, int to){
	edge &E = e[edges];
	E.from = from;
	E.to = to;
	E.next = next[from];
	next[from] = edges++;
}

int main(void){
	int t; scanf("%d", &t);
	for(int c, r; t-- && scanf("%d%d", &c, &r) == 2; ){
		int head = 0, tail = 0;
		edges = 0;
		FOR(j, r) FOR(i, c) next[(i << 10) | j] = -1;
		FOR(j, r) FOR(i, c){
			int mask = (i << 10) | j;
			v[mask] = dep[mask] = 0;
			scanf("%s", expr);
			if(sscanf(expr, "%d", v + mask) != 1){ // we have a formula
				for(char *p = strtok(expr+1, "+"); p != NULL; p = strtok(NULL, "+")){
					int col = 0, row = 0, z;
					for(z = 0; p[z] >= 'A' && p[z] <= 'Z'; ++z)
						col = (col * 26) + p[z] - 'A' + 1;
					row = atoi(p + z);
					add_edge((col << 10) | row, mask);
					++dep[mask];
				}
			} else q[tail++] = (i << 10) | j;
		}
		for(int at = q[head++], to; head != tail; at = q[head++])
			for(int en = next[at]; en != -1; en = e[en].next){
				v[to = e[en].to] += v[at];
				if(!--dep[to]) q[tail++] = to;
			}
		FOR(j, r) FOR(i, c) printf("%d%c", v[(i << 10) | j], i == c ? 10 : 32);
	}
	return 0;
}

