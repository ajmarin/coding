#include <algorithm>
#include <cstdio>
using namespace std;
const int NN = 1024;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
int pos[NN], v[NN], v2[NN];
int main(void){
	for(int n, T = 1; scanf("%d", &n) == 1 && n; ++T){
		FOR(i, n) scanf("%d", v + i), pos[v[i]] = i, v2[i] = v[i];
		sort(v2, v2 + n);
		int cost = 0, swapper = v2[0];
		FOR(i, n){
			int idx = -1, steps = 0, z = NN;
			FOR(j, n) if(v[j] != v2[j] && v[j] < z) idx = j, z = v[j];
			if(idx == -1) break;
			while(v[idx] != v2[idx]){
				z = pos[v2[idx]];
				cost += v[z];
				swap(v[z], v[idx]);
				swap(pos[v2[idx]], pos[v[idx]]);
				idx = pos[v[idx]];
				++steps;
			}
			if(steps * (v[idx] - swapper) < 2*(v[idx]+swapper))
				cost += v[idx] * steps;
			else 
				cost += 2*(v[idx] + swapper) + swapper * steps;
		}
		printf("Case %d: %d\n\n", T, cost);
	}
	return 0;
}

