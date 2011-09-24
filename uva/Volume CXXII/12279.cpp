#include <cstdio>

int main(void){
	for(int c = 0, n; scanf("%d", &n) == 1 && n; ){
		int cnt = 0;
		for(int i = 0, z; i < n; ++i){
			scanf("%d", &z);
			cnt += !z;
		}
		printf("Case %d: %d\n", ++c, n - (cnt << 1));
	}
	return 0;
}

