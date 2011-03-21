#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;
const int N = 1024;
vector < int > adj[N];
map < string, int > m;
int cnt, n, w;
int c[N], ord[N], path[N];
bool root[N];
string snm[N];
char name[16];
void dfs(int d, int x){
	int sz = adj[x].size();
	path[d] = x;
	if(d >= w) ++c[path[d - w]];
	for(int i = 0; i < sz; ++i)
		dfs(d + 1, adj[x][i]);
}
int idx(char *person){
	int &x = m[person];
	if(!x){
		snm[x = ++cnt] = person;
#ifdef DBG
		printf("%s -> %d\n", person, x);
#endif
	}
	return x;
}
bool cmp(int a, int b){
	return c[a] > c[b] || (c[a] == c[b] && snm[a] < snm[b]);
}
int main(void){
	int p, son_idx, sons, t; scanf("%d", &t);
	for(int tree = 0; tree++ < t; ){
		cnt = 0;
		m.clear();
		scanf("%d %d", &n, &w);
		for(int i = 0; i < N; ++i){
			c[i] = 0;
			root[i] = 1;
			adj[i].clear();
			ord[i] = i;
		}
		for(int nc = 0; nc < n; ++nc){
			scanf("%s %d", name, &sons);
			p = idx(name);
			for(int i = 0; i < sons; ++i){
				scanf("%s", name);
				adj[p].push_back(son_idx = idx(name));
				root[son_idx] = 0;
			}
		}
		for(int i = 1; i <= cnt; ++i) if(root[i]) dfs(0, i);
		sort(ord + 1, ord + cnt + 1, cmp);
		printf("Tree %d:\n", tree);
		int shown = 0;
		for(int change = 0, i = 1, j = 1; change < 3 && shown < 3; ++change){
			if(c[ord[j]] == 0) break;
			while(j <= cnt && c[ord[j]] == c[ord[i]]){
				printf("%s %d\n", snm[ord[j]].c_str(), c[ord[j]]);
				++j;
			}
			shown += (j - i);
			i = j;
		}
		if(tree != t) puts("");
	}
	return 0;
}

