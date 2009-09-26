/////////////////////////////////
// 10003 - Cutting Sticks
/////////////////////////////////
#include <cstdio>
#include <cstring>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)<(b)?(b):(a))
#define INF 1077952576
int cost[52][52], c[52];
int cut(int l, int r){
	if(r - l <  2) cost[l][r] = 0;
	if(cost[l][r] == INF)
		for(int i = l+1; i < r; i++){
			int temp =  c[r]-c[l] +	cut(l,i) + cut(i,r);
			cost[l][r] = MIN(cost[l][r],temp);
		}
	return cost[l][r];
}
int main(void){
	int cuts, i, size;
	while(scanf("%d",&size) && size){
		scanf("%d",&cuts);
		c[0] = 0;
		memset(cost, 64, sizeof(cost));
		for(i = 1; i <= cuts; i++) scanf("%d",&c[i]);
		c[i] = size;
		printf("The minimum cutting is %d.\n",cut(0,i));
	}
	return 0;
}

