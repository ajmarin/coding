#include <cstdio>
#include <cstring>

char subject[128][32];
int cost[128];

int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		int i, D, n; scanf("%d", &n);
		for(i = 0; i < n; ++i)
			scanf("%s %d", subject[i], cost + i);
		scanf("%d %s", &D, subject[n]);
		for(i = 0; i < n; ++i)
			if(!strcmp(subject[i], subject[n])) break;
		printf("Case %d: ", cnum);
		if(i == n || cost[i] > D + 5) puts("Do your own homework!");
		else if(cost[i] <= D)  puts("Yesss");
		else puts("Late");
	}
	return 0;
}

