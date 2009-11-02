#include <cstdio>

#define MIN(a,b) ((a)<(b)?(a):(b))

int R, C, Q;
int INI, FIM;
int n[560][560];
int main(void){
	while(scanf("%d%d",&R,&C) && (R||C)){
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				scanf("%d",&n[i][j]);
		scanf("%d",&Q);
		for(int q = 0; q < Q; ++q){
			int max = -1;
			scanf("%d%d",&INI,&FIM);
			for(int i = 0; i < R; ++i){
				int u, v;
				for(u = 0, v = C - 1; u < v; ){
					int c = (u + v) >> 1;
					if(n[i][c] < INI) u = c +1; else v = c;
				}
				while(u < (C - 1) && n[i][u] < INI) u++;
				while(u && n[i][u-1] >= INI) u--;
				int y = u;
				if(n[i][y] < INI || n[i][y] > FIM) continue;
				for(u = 0, v = MIN(R - i - 1, C - y - 1); u < v; ){
					int c = (u + v) >> 1;
					if(n[i + c][y + c] < FIM) u = c + 1; else v = c;
				}
				int x = i + u, y2 = y + u;
				while(x < (R - 1) && y2 < (C - 1) && n[x + 1][y2 + 1] <= FIM)
					++x, ++y2;
				while(x &&  y2 && n[x][y2] > FIM) --x, --y2;
				int valor = y2 - y;
				if(valor > max) max = valor;
			}
			printf("%d\n", max + 1);
		}
		printf("-\n");
	}
	return 0;
}

		
