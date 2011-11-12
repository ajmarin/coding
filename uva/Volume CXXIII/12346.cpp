#include <algorithm>
#include <cstdio>
using namespace std;

long long F[32], C[32];
struct option {
	long long cost, flow;
	bool operator<(const option& o) const {
		return flow < o.flow || (flow == o.flow && cost < o.cost);
	}
} opt[(1 << 20) + 5];

int main(void){
	for(int cnum = 0, m, n, q, u, v; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i) scanf("%lld %lld", &F[i], &C[i]);
		for(int i = 0; i < 1 << n; ++i){
			opt[i].cost = opt[i].flow = 0;
			for(int j = 0; j < n; ++j) if(i & (1 << j)){
				opt[i].cost += C[j];
				opt[i].flow += F[j];
			}
		}
		opt[1<<n].flow = 0;
		sort(opt, opt + (1 << n));
		scanf("%d", &q);
		for(long long T, V; cnum++ < q && scanf("%lld %lld", &V, &T) == 2; ){
			V = (V + T - 1) / T;
			for(u = 0, v = 1 << n; u < v; ){
				m = (u + v) >> 1;
				if(opt[m].flow < V) u = m + 1;
				else v = m;
			}
			printf("Case %d: ", cnum);
			if(opt[u].flow >= V){
				long long min_cost = opt[u].cost;
				while(++u < 1 << n) if(opt[u].cost < min_cost) min_cost = opt[u].cost;
				printf("%lld\n", min_cost);
			} else puts("IMPOSSIBLE");
		}
	}
	return 0;
}

