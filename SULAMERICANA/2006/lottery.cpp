#include <cstdio>
#include <cstring>
int oc[101];
int main(void){
	int c, i, j, idx, k, min, n, v;
	while(scanf("%d%d%d",&n,&c,&k) && n){
		memset(oc,0,(k+1)<<2);
		for(i = 0; i < n; i++)
			for(j = 0; j < c; j++)
				scanf("%d",&v), oc[v]++;
		min = 1<<14;
		for(i = 1; i <= k; i++)
			if(min > oc[i]) min = oc[i], idx = i;
		bool first = 1;
		for(i = idx; i <= k; i++)
			if(first) printf("%d",idx), first = 0;
			else if(oc[i] == min) printf(" %d",i);
		putchar('\n');
	}
	return 0;
}
