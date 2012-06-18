#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,n) for(int i = 1; i <= n; ++i)
const int NN = 512;

char city[NN][32];
int q[500123];
vector < int > p[NN];
int ccnt;
map < string, int > m;

int adj[NN][NN];

int get_index(char *name){
	int &z = m[name];
	if(!z){
		z = ++ccnt;
		strcpy(city[ccnt], name);
		p[z].clear();
	}
	return z;
}

int main(void){
	char ca[32], cb[32];
	for(int a, b, cn = 1, f = 1, n, z; scanf("%d", &n) == 1; f = 0, ++cn){
		if(!f) puts("");
		ccnt = 0;
		m.clear();
		FOR(i, n){
			scanf("%s %s %d", ca, cb, &z);
			a = get_index(ca);
			b = get_index(cb);
			if(adj[a][b] >> 10 != cn || z < adj[a][b])
				adj[a][b] = adj[b][a] = z | (cn << 10);
		}
		scanf("%s %s", ca, cb);
		a = get_index(ca);
		b = get_index(cb);
		int t = 0;
		q[t++] = a;
#define D(x) ((x & 0x3FF00000) >> 20)
#define S(x) ((x & 0xFFC00) >> 10)
#define W(x) (x & 0x3FF)
		for(int h = 0; h != t && p[b].size() == 0; ++h){
			int depth = D(q[h]);
			int speed = S(q[h]);
			int u = W(q[h]);
			FOR(v, ccnt) if(adj[u][v] >> 10 == cn){
				int nspeed = adj[u][v] & 0x3FF;
				if(nspeed < speed || (p[u].size() && v == W(p[u][p[u].size() - 1]))) continue;
				p[v].push_back(u | (nspeed << 10) | (depth << 20));
				q[t++] = v | (nspeed << 10) | ((depth + 1) << 20);
			}
		}
		if(!p[b].size()) puts("No valid route.");
		else {
			t = 0;
			for(int at = b, d = D(p[b][0]) + 1, speed = S(p[b][0]); ; ){
				q[t++] = at;
				int idx = 1 << 10, nspeed;
				for(int i = 0; i < int(p[at].size()); ++i){
					if(D(p[at][i]) == d - 1 && S(p[at][i]) <= speed && W(p[at][i]) < idx){
						nspeed = S(p[at][i]);
						idx = W(p[at][i]);
					}
				}
				if(idx == 1 << 10) break;
				at = idx;
				speed = nspeed;
				--d;
			}
			while(t--) printf("%s%c", city[q[t]], t ? 32: 10);
		}
	}
	return 0;
}

