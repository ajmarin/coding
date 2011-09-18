#include <cstdio>
#include <cstdlib>

char map[50000];
char ans[63000];
int main(void){
	int N, R1, R2, C1, C2, cnum = 0;
	for(int i = 0; i < 50000; i++) map[i] = 'a' + (i % 26);
	while(scanf("%d%d%d%d%d",&N,&R1,&C1,&R2,&C2) && N){
		printf("Case %d:\n",++cnum);
		int tlines = 2 * N - 1;
		++R2; ++C2;
		register char *p = ans;
		for(int i = R1; i < R2; ++i){
			int line = abs((i % tlines) - (N - 1));
			int maxd = N - 1 - line;
			for(int j = C1; j < C2; ++j){
				int col = abs((j % tlines) - (N - 1));
				if(col > maxd) *p++ = '.';
				else *p++ = map[ col + line ];
			}
			*p++ = 10;
		}
		*--p = 0;
		puts(ans);
	}
	return 0;
}

