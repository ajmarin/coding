#include <algorithm>
#include <cstdio>
using namespace std;
const int NN = 1024;
struct g { int p, j, n; } gp[NN], gj[NN];
bool chosen[NN];
char who[16];
bool j_sort(g a, g b){ return a.j > b.j || (a.j == b.j && a.p < b.p); }
bool p_sort(g a, g b){ return a.p > b.p || (a.p == b.p && a.j < b.j); }
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		int gjp, gpp, jv, pv, player; 
		scanf("%d %s", &n, who);
		for(int i = 0; i < n; ++i){
			scanf("%d %d", &pv, &jv);
			gj[i].n = gp[i].n = i;
			gj[i].p = gp[i].p = pv;
			gj[i].j = gp[i].j = jv;
			chosen[i] = 0;
		}
		sort(gj, gj + n, j_sort);
		sort(gp, gp + n, p_sort);
		player = who[0] == 'J';
		gpp = gjp = jv = pv = 0;
		for(int i = 0; i < n; ++i){
			if(player == 1){ // Jan choosing 
				while(chosen[gj[gjp].n]) gjp++;
				chosen[gj[gjp].n] = 1;
				jv += gj[gjp++].j;
			} else { // Petra choosing
				while(chosen[gp[gpp].n]) gpp++;
				chosen[gp[gpp].n] = 1;
				pv += gp[gpp++].p;
			}
			player = 1 - player;
		}
		printf("%d %d\n", pv, jv);
	}
	return 0;
}

