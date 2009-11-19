#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a, 0, b)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define NN 1005

struct nome {
	string w;
	bool operator<(const nome &x) const { 
		int lim = MIN(w.length(), x.w.length());
		for(int i = 0; i < lim; ++i)
			if(tolower(w[i]) < tolower(x.w[i])) return 1;
			else if(tolower(w[i]) > tolower(x.w[i])) return 0;
		return w.length() < x.w.length();
	}
} n[NN];
map < string, int > m;
int cnt = 0, f, maxd;
int idx[2];
vector < int > adj[NN];
bool v[NN];

void dfs(int k, int d){
	if(d > maxd){
		idx[f] = k;
		maxd = d;
	}
	v[k] = 1;
	for(vector<int>::iterator it = adj[k].begin(); it != adj[k].end(); it++)
		if(!v[*it]) dfs(*it, d + 1);
}


int insere(string x){
	map < string, int > :: iterator it = m.find(x);
	if(it == m.end()) return n[cnt].w = x, m[x] = cnt++;
	return (*it).second;
}
int main(void){
	int a, b, N;
	char na[64], nb[64];
	while(scanf("%d", &N) == 1){
		memset(v, 0, NN);
		m.clear(); cnt = f = maxd = 0;
		FOR(i, N){
			scanf("%s %s", &na, &nb);
			a = insere(string(na));
			b = insere(string(nb));
			adj[a].push_back(b);
			adj[b].push_back(a);
			v[b] = 1;
		}
		int chosen;
		FOR(i, cnt) if(!v[i]){ chosen = i; break;}
#ifdef DEBUG
		printf("%s was chosen\n", n[chosen].w.c_str());
#endif
		memset(v, 0, cnt);
		dfs(chosen, 0);
#ifdef DEBUG
		printf("%s is further\n", n[idx[0]].w.c_str());
#endif
		maxd = 0; f = 1;
		memset(v, 0, cnt);
		dfs(idx[0], 0);
#ifdef DEBUG
		printf("\t%s (%d)\n", n[idx[1]].w.c_str(), maxd);
#endif
		if(n[idx[0]] < n[idx[1]])
			printf("%s %s %d\n", n[idx[0]].w.c_str(), n[idx[1]].w.c_str(), maxd);
		else printf("%s %s %d\n", n[idx[1]].w.c_str(), n[idx[0]].w.c_str(), maxd);
		FOR(i, cnt) adj[i].clear();
	}
	return 0;
}

