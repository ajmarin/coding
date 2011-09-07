#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
const int NN = 4096;
int cx[NN], cy[NN], cbp[64];
int min(int a, int b){ return a < b ? a : b; }
int abs(int a){ return a < 0 ? -a : a; }
int main(void){
	int T; scanf("%d", &T);
	int h, l, z;
	while(T--){
		scanf("%d %d", &h, &l);
		FOR(i, NN) cx[i] = cy[i] = -1;
		FOR(i, 64) cbp[i] = 0;
		FOR(i, h) FOR(j, l){
			scanf("%d", &z);
			if(z != -1) cx[z] = i, cy[z] = j;
		}
		long long cost = 0;
		for(int i = 1; cx[i] != -1; ++i){
			cost += 20 * cx[i];
			int diff = abs(cy[i] - cbp[cx[i]]);
			cost += min(diff, l - diff) * 5;
			cbp[cx[i]] = cy[i];
		}
		printf("%lld\n", cost);
	}
	return 0;
}

