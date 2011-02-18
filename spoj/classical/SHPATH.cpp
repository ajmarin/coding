#include <cstdio>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;
map < string, int > m;
vector < pair < int, int > > adj[10048];
int dist[10048];
const int INF = 1 << 30;
int main(void){
	char city1[16], city2[16];
	int at, cost, from, k, n, sz, t, to, x, w; scanf("%d", &t);
	while(t--){
		m.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%s %d", city1, &k);
			m[city1] = i;
			adj[i].clear();
			for(int j = 0; j < k; ++j){
				scanf("%d %d", &to, &w);
				adj[i].push_back(make_pair(--to, w));
			}
		}
		scanf("%d", &k);
		while(k--){
			scanf("%s %s", city1, city2);
			from = m[city1], to = m[city2];
			for(int i = 0; i < n; ++i) dist[i] = (i != from) << 30;
			priority_queue < pair< int, int > > q;
			q.push(make_pair(0, from));
			while(!q.empty()){
				pair < int, int > pp = q.top(); q.pop();
				at = pp.second, cost = -pp.first, sz = adj[at].size();
				if(dist[at] < cost) continue;
				if(at == to) break;
				for(int i = 0; i < sz; ++i){
					x = adj[at][i].first, w = adj[at][i].second;
					if(dist[x] > cost + w) q.push(make_pair(-(dist[x] = cost + w), x));
				}
			}
			printf("%d\n", dist[to]);
		}
	}
	return 0;
}

