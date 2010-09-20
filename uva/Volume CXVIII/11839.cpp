#include <cstdio>

int main(void){
	int n, v;
	while(scanf("%d", &n) && n){
		for(int k = 0; k < n; ++k){
			char ans = 0;
			for(int i = 0; i < 5; ++i){
				scanf("%d", &v);
				ans = v < 128 ? ans  ? '*' : i + 'A' : ans;
			}
			if(ans) putc(ans, stdout);
			else putc('*', stdout);
			putc(10, stdout);
		}
	}
	return 0;
}

