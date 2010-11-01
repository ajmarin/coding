#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define NN 200000
map < int, int > m;
vector < int > adj[NN];
bool v[NN];
int vis;
bool dfs(int k, int p){
	bool ret = 0;
	v[k] = 1;
	vis++;
	vector < int >:: iterator it;
	for(it = adj[k].begin(); it != adj[k].end(); ++it){
		if(!v[*it]) ret |= dfs(*it, k); 
		else if(*it != p) ret = 1;
	}
	return ret;
}
int main(void){
	for(int i = 0; i < NN; ++i) v[i] = 0;
	for(int K, W; scanf("%d %d", &K, &W) == 2 && (K || W); ){
		int a, b, cnt = 0, dfscnt = 0, fail = 0;
		bool useless;
		map < int, int >::iterator it;
		m.clear();
		for(int i = 0; i < W; ++i){
			scanf("%d %d", &a, &b);
			if((it = m.find(a)) != m.end()) a = it -> second;
			else a = m[a] = cnt++;
			if((it = m.find(b)) != m.end()) b = it -> second;
			else b = m[b] = cnt++;
			useless = 0;
			for(unsigned int j = 0; j < adj[a].size(); ++j)
				useless |= adj[a][j] == b;
			if(useless) continue;
			adj[a].push_back(b);
			adj[b].push_back(a);
			fail |= adj[a].size() == 3 || adj[b].size() == 3;
		}
		if(!fail) {
			vis = 0;
			for(int i = 0; i < cnt; ++i)
				if(!v[i]){
					if(dfs(i, -1) && (vis != K || dfscnt)){ fail = 1; break; }
					dfscnt++;
				}
		}
		if(fail) puts("N");
		else puts("Y");
		for(int i = 0; i < cnt; ++i) v[i] = 0, adj[i].clear();
	}
	return 0;
}

