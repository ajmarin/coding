#include <cstring>
#include <cstdio>

#define DEBAG

struct emoticon {
	char w[18], *l;
	int len;
} e[100];
char line[128];
bool ends[128];

int main(void){
	int ans, N, M;
	while(scanf("%d %d\n", &N, &M) && N){
		memset(ends, 0, sizeof(ends));
		ans = 0;
		for(int i = 0; i < N; ++i){
			fgets(e[i].w, 18, stdin);
			e[i].w[(e[i].len =  strlen(e[i].w) - 1)] = 0;
			e[i].l = e[i].w + e[i].len - 1;
			ends[*e[i].l] = 1;
		}
		for(int i = 0; i < M; ++i){
			fgets(line, 128, stdin);
			char *ini = line, *fim = line;
			while(*fim){
				while(*fim && !ends[*fim]) ++fim;
				if(ends[*fim]){
					int L = fim - ini + 1;
					for(int j = 0; j < N; ++j){
						if(L < e[j].len || *fim != *(e[j].l)) continue;
						char *f = fim, *x = e[j].l;
						do { 
							x--; f--;
						} while(x >= e[j].w && *x == *f);
						if(x < e[j].w){
							++ans;
							ini = fim + 1;
							*fim = ' ';
							break;
						} 
					}
					++fim;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

