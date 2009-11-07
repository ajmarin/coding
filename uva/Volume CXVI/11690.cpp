#include <cstdio>
#include <vector>

using namespace std;

#define NN 10000
#define FOR(a,b) for(int a = 0; a < b; ++a)
#define tr(x) for(typeof(x.begin())it = x.begin(); it != x.end(); ++it)

vector < int > adj[NN];
bool v[NN], possible;
int n, m, s, visited, M[NN];
void dfs(int k){
	v[k] = 1;
	s += M[k];
	tr(adj[k]) if(!v[*it]) dfs(*it);
}

int main(void){
	int a, b, N;
	scanf("%d",&N);
	while(N--){
		scanf("%d%d",&n,&m);
		possible = 1;
		FOR(i, n) {
			scanf("%d",&M[i]);
			adj[i].clear();
			v[i] = 0;
		}
		FOR(i, m){
			scanf("%d%d",&a,&b);
			//printf("Connecting %d with %d\n",a,b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		FOR(i, n)
			if(!v[i]){
				s = 0;
				dfs(i);
				if(s != 0) possible = 0;
			}
		(possible) ? puts("POSSIBLE") : puts("IMPOSSIBLE");
	}
	return 0;
}

