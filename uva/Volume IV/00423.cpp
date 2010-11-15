#include <cstdio>
#include <cstdlib>
const int INF = 0x3fffffff;
int d[128], m[128][128];
char number[32];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int i = 0; i < 128; ++i) m[i][i] = 0;
	for(int n; scanf("%d", &n) == 1; ){
		int maxd = 0;
		for(int i = 1; i < n; ++i)
			for(int j = 0; j < i; ++j){
				scanf("%s", number);
				if(number[0] == 'x') m[i][j] = INF;
				else m[i][j] = atoi(number);
				m[j][i] = m[i][j];
			}
		for(int k = 0; k < n; ++k) d[k] = INF;
		d[0] = 0;
		for(int k = 0; k < n; ++k)
			for(int i = 0; i < n; ++i)
				for(int j = 0; j < n; ++j)
					d[j] = min(d[j], d[i] + m[i][j]);
		for(int i = 0; i < n; ++i) if(d[i] > maxd) maxd = d[i];
		printf("%d\n", maxd);
	}
	return 0;
}

