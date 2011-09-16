#include <cstdio>
#include <cstring>
#include <algorithm>
struct P {
	int p; char n[32];
	bool operator()(P a, P b){
		return (a.p > b.p || (a.p == b.p && strcmp(a.n,b.n)<0));
	}
} plr[1024];
int main(void){
	int cc, i, j, max, min, n, v;
	for(int t = 1; scanf("%d",&n) && n; t++){
		for(i = 0; i < n; i++){
			scanf("%s",&plr[i].n);
			min = 1001; max = -1;
			plr[i].p = 0;
			for(j = 0; j < 12; j++){
				scanf("%d",&v);
				if(v < min) min = v;
				if(v > max) max = v;
				plr[i].p += v;
			}
			plr[i].p -= (min+max);
		}
		std::sort(plr,plr+n,P());
		printf("Teste %d\n",t);
		printf("1 %d %s\n",plr[0].p,plr[0].n);
		for(cc = i = 1; i < n; i++){
			if(plr[i-1].p > plr[i].p) cc = i+1;
			printf("%d %d %s\n",cc,plr[i].p,plr[i].n);
		}
		putchar('\n');
	}
	return 0;
}
