#include <cstdio>
int w[16];
int main(void){
	for(int c = 0, n, z; scanf("%d", &n) == 1 && n >= 0; ){
		printf("Case %d:\n", ++c);
		for(int i = 0; i < 12; ++i) scanf("%d", &w[i]);
		for(int i = 0; i < 12; ++i){
			scanf("%d", &z);
			if(n >= z) n -= z, puts("No problem! :D");
			else puts("No problem. :(");
			n += w[i];
		}
	}
	return 0;
}

