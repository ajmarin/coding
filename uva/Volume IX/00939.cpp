#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
using namespace std;

const char *types[] = { "non-existent", "recessive", "dominant" };

struct person {
	char n[32];
	int s, t;
	bool operator<(const person& p) const { return strcmp(n, p.n) < 0; }
	void ct(){ t = (s >= 2) + (s > 2); }
} p[1<<12];
struct edge { int next, to; } e[1<<12];

int head[1<<12], deg[1<<12], q[1<<12];
int ecnt, pn;
map < string, int > m;

int get(char *s){
	int &z = m[s];
	if(!z){
		z = ++pn;
		p[z].s = deg[z] = 0;
		head[z] = -1;
		strcpy(p[z].n, s);
	}
	return z;
}

void add_edge(int from, int to){
	edge &E = e[ecnt];
	E.to = to;
	E.next = head[from];
	++deg[to];
	head[from] = ecnt++;
}

int main(void){
	char name[32], rel[32];
	for(int n; scanf("%d", &n) == 1 && n; ){
		ecnt = pn = 0;
		m.clear();
		for(int a, i = 0; i < n; ++i){
			scanf("%s %s", name, rel);
			a = get(name);
			if(!strcmp(rel, "dominant")) p[a].t = 2, p[a].s = 3;
			else if(!strcmp(rel, "non-existent")) p[a].t = 0, p[a].s = 0;
			else if(!strcmp(rel, "recessive")) p[a].t = 1, p[a].s = 2;
			else add_edge(a, get(rel));
		}
		int t = 0;
		for(int i = 1; i <= pn; ++i) if(!deg[i]) q[t++] = i;
		for(int h = 0; h < t; ++h){
			p[q[h]].ct();
			for(int at = head[q[h]]; at != -1; at = e[at].next){
				p[e[at].to].s += p[q[h]].t;
				if(!--deg[e[at].to]) q[t++] = e[at].to;
			}
		}
		sort(p + 1, p + 1 + pn);
		for(int i = 1; i <= pn; ++i)
			printf("%s %s\n", p[i].n, types[p[i].t]);
	}
	return 0;
}

