#include <cstdio>

int m[128][128];
int main(void){
	for(int i = 0; i < 128; ++i) m[i][0] = 0;
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i)
			for(int j = 1; j <= n; ++j){
				scanf("%d", &m[i][j]);
				m[i][j] += m[i][j - 1];
			}
		int max_s = 1<<31;
		for(int l = 0; l < n; ++l)
			for(int r = l + 1; r <= n; ++r){
				int s = 0;
				for(int i = 0; i < n; ++i){
					s += m[i][r] - m[i][l];
					if(s > max_s) max_s = s;
					if(s < 0) s = 0;
				}
			}
		printf("%d\n", max_s);
	}
	return 0;
}

