#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define N 400
#define INF 2147483647

struct edge {
	int c, f, t;
} e[79800];

map < string, int > m;
vector < edge * > v[N];
char subway[16], other[16];
int C, S, connected, price;
int p[N], r[N];
bool s[N];

void prim(int x){
	int idx = -1, min = INF, n;
	vector < edge * > :: iterator it;
	s[x] = 1;
	++connected;
	price += r[x];
	for(it = v[x].begin(); it != v[x].end(); it++){
		edge * e = *it;
		if(e->f == x) n = e->t;
		else n = e->f;
		if(s[n]) continue;
		if(r[n] > e->c) r[n] = e->c, p[n] = x;
	}
	for(int i = 0; i < S; ++i){
		if(s[i]) continue;
		if(r[i] < min) min = r[i], idx = i;
	}
	if(idx != -1) prim(idx);
}

int main(void){
	int cost, index;
	while(scanf("%d %d", &S, &C) && S){
		connected = price = 0;
		m.clear();
		FOR(i, S){
			scanf("%s", subway);
			m[string(subway)] = i;
			p[i] = -1;
			r[i] = INF;
			s[i] = 0;
			v[i].clear();
		}
		FOR(i, C){
			scanf("%s %s %d", subway, other, &cost);
			int a = m[string(subway)], b = m[string(other)];
			e[i].f = a; e[i].t = b; e[i].c = cost; 
			v[a].push_back(&e[i]);
			v[b].push_back(&e[i]);
		}
		scanf("%s", subway);
		index = m[string(subway)];
		r[index] = 0;
		prim(index);
		if(connected == S) printf("%d\n", price);
		else printf("Impossible\n");
	}
	return 0;
}

