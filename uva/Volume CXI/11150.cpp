#include <cstdio>

int max(int a, int b){ return a > b ? a : b; }

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int ans = 0, full, empty, test;
		for(int i = 0; i < 3; ++i){
			test = 0;
			full = n;
			empty = i;
			do {
				// drink the full ones
				test += full;
				empty += full;
				// return each 3
				full = empty / 3;
				empty %= 3;
			} while(full > 0);
			if(empty < i) test = 0;
			ans = max(ans, test);
		}
		printf("%d\n", ans);
	}
	return 0;
}

