#include <cstdio>
#define MIN(a,b) ((a<b)?(a):(b))
int c, cost, costL, costR, i, idx, j, min, n, p, pts;
int main(void){
	scanf("%d",&n);
	min = 1<<30;
	for(i = 0; i < n; i++){
		scanf("%d",&pts);
		p = c = costR = costL = 0;
		for(j = 0; j < pts; j++){
			p = c;
			scanf("%d",&c);
			if(j){
				if(c > p) costR += (c-p);
				else if(c < p) costL += (p-c);
			}
		}
		cost = MIN(costL,costR);
		if(min > cost) min = cost, idx = i+1;
	}
	printf("%d\n",idx);
	return 0;
}
