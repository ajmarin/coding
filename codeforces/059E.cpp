#include <cstdio>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define FOR(i,e)	for(int i = 0; i < e; ++i)
#define MP			make_pair
const int N = 3001;
set < ll > f;
int p[N][N], ans[N];
vi adj[N];
queue < pair < pii, int > > q;
long long mask(int a, int b, int c){ return 1000LL * (a * 1000 + b) + c; }
int main(void){
	int a, b, c, depth = -1, k, m, n; scanf("%d %d %d", &n, &m, &k);
	bool over = false;
	FOR(i, m){
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	} 
	++n;
	FOR(i, n) FOR(j, n) p[i][j] = -1;
	FOR(i, k){
		scanf("%d %d %d", &a, &b, &c);
		f.insert(mask(a, b, c));
	}
	p[0][1] = 0;
	q.push(MP(MP(0, 1), 0));
	while(!q.empty()){
		int d, next, u, v, z;
		pair<pii,int>x = q.front(); q.pop();
		d = x.second;
		u = x.first.first;
		v = x.first.second;
		z = adj[v].size();
		FOR(i, z){
			next = adj[v][i];
			if(f.find(mask(u, v, next)) == f.end() && p[v][next] < 0){
				p[v][next] = u;
				q.push(MP(MP(v, next), d + 1));
				over |= next == n - 1;
			}
		}
		if(over){
			depth = d + 1;
			b = v;
			c = n - 1;
			break;
		}
	}
	printf("%d\n", depth++);
	for(int i = depth; i--; ){
		ans[i] = c;
		a = b;
		b = p[b][c];
		c = a;
	}
	FOR(i, depth) printf("%d%c", ans[i], i == depth - 1 ? '\n' : ' ');
	return 0;
}
