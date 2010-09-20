#include <cstdio>

int r[128][128];
int s[128];
int p[128];

int main(void){
	int G, K, S, P;
	while(scanf("%d %d", &G, &P) && G){
		for(int i = 0; i < G; ++i)
			for(int j = 0; j < P; ++j){
				scanf("%d", &r[i][j]);
				r[i][j]--;
			}
		scanf("%d", &S);
		for(int i = 0; i < S; ++i){
			for(int j = 0; j < P; ++j) p[j] = 0;
			scanf("%d", &K);
			int max = 0;
			for(int j = 0; j < K; ++j) scanf("%d", &s[j]);
			for(int j = 0; j < G; ++j)
				for(int k = 0; k < P; ++k)
					if(r[j][k] < K){
					   	p[k] += s[r[j][k]];
						if(p[k] > max) max = p[k];
					}
			int shown = 0;
			for(int k = 0; k < P; ++k)
				if(p[k] == max){
					if(shown) putc(32, stdout);
					printf("%d", k + 1);
					shown = 1;
				}
			putc(10, stdout);
		} 
	}
	return 0;
}

