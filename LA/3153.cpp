#include <cstdio>
#include <algorithm>
#define LOOP(k) for((k) = 0; (k) < n; (k)++)
#define ILOOP(k) for(int (k) = 0; (k) < n; (k)++)
int d[20][20], t[20], t2[20];
int max_depth, max_poss, n;
void bt(int vis, int time_left, int mask, int depth){
	if(time_left < 0) return;
	if(depth > max_depth) max_depth = depth;
	if(max_depth < max_poss)
		ILOOP(i) if(!(mask&(1<<i)) && d[vis][i] <= time_left)
			bt(i, time_left - d[vis][i], mask|(1<<i),depth+1);
}
int main(void){
	int i, j;
	while(scanf("%d",&n) && n){
		LOOP(i)	scanf("%d",&t[i]), t2[i] = t[i];
		LOOP(i) LOOP(j) scanf("%d",&d[i][j]), d[i][j] += t[j];
		std::sort(t2,t2+n); max_poss = 420;
		LOOP(i)	if((max_poss -= t2[i]) < 0) break;
		max_poss = i; max_depth = 0;
		LOOP(i)	bt(i, 420 - t[i], (1<<i), 1);
		printf("%d\n",max_depth);
	}
	return 0;
}

