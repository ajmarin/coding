#include <cstdio>

const double lim = 1 - (1e-9);
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		if(n == 0) { puts("0"); continue; }
		int cnt = 1; double w, z; scanf("%lf", &w);
		for(int i = 1; i < n; ++i){
			scanf("%lf", &z);
			if(z - w > lim) w = z, ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

