#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main(void){
	int gi, G, mi, M, t; scanf("%d", &t);
	while(t--){
		scanf("%d %d", &G, &M);
		vector<int>g(G,0), m(M,0);
		for(int i = 0; i < G; ++i) scanf("%d", &g[i]);
		for(int i = 0; i < M; ++i) scanf("%d", &m[i]);
		sort(g.begin(), g.end());
		sort(m.begin(), m.end());
		for(gi = mi = 0; mi < M; ){
			while(gi < G && g[gi] < m[mi]) ++gi;
			if(gi == G) break;
			while(mi < M && m[mi] <= g[gi]) ++mi;
		}
		puts(mi == M ? "Godzilla" : "MechaGodzilla");
	}
	return 0;
}

