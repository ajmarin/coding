#include <cstdio>
#include <cstring>
int p[1024];
int main(void){
	bool poss;
	int dpos, i, n, pos, who;
	while(scanf("%d",&n) && n){
		memset(p,0,n<<2);
		poss = 1;
		for(i = 0; i < n; i++){
			scanf("%d%d",&who,&dpos);
			pos = i + dpos;
			if(pos < 0 || pos >= n || p[i+dpos]) poss = 0;
			if(poss) p[pos] = who;
		}
		if(poss){
			for(i = 0; i < n; i++){
				if(i) putchar(' ');
				printf("%d",p[i]);
			}
			putchar('\n');
		}
		else printf("-1\n");
	}
	return 0;
}
