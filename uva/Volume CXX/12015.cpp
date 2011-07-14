#include <cstdio>

char url[16][128];
int v[16];
int main(void){
	int t; scanf("%d", &t);
	for(int ncase = 1; t--; ++ncase){
		int maxv = -1;
		for(int i = 0; i < 10; ++i){
			scanf("%s %d", url[i], v + i);
			if(v[i] > maxv) maxv = v[i];
		}
		printf("Case #%d:\n", ncase);
		for(int i = 0; i < 10; ++i) if(v[i] == maxv) puts(url[i]);
	}
	return 0;
}

