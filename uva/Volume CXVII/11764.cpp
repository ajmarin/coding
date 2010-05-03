#include <cstdio>

int main(void){
	int h, l, n, p, r, t;
	scanf("%d", &t);
	for(int cnum = 0; cnum < t; ){
		scanf("%d", &n);
		h = l = 0;
		for(int i = 0; i < n; ++i){
			p = r;
			scanf("%d", &r);
			if(i){
				h += r > p;
				l += r < p;
			}
		}
		printf("Case %d: %d %d\n", ++cnum, h, l);
	}
	return 0;
}

