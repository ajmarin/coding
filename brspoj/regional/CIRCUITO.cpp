#include <cstdio>
 
#define P 1024
 
int p, n, c;
int b[P], d[P];
int ans;
 
int main(void) {
	int i;
	 
	while(scanf("%d %d %d", &p, &n, &c)) {
		if(p == 0 && n == 0 && c == 0) break;
		 
		for(i = 0; i < p; i++) d[i] = 0;
		 
		ans = 0;
		while(n--) {
			for(i = 0; i < p; i++) {
				scanf("%d", &b[i]);
				if(b[i]) d[i]++;
				else {
					if(d[i] >= c) ans++;
					d[i] = 0;
				}
			}
		}
		 
		for(i = 0; i < p; i++) if(d[i] >= c) ans++;
		 
		printf("%d\n", ans);
	}
	 
	return 0;
}

