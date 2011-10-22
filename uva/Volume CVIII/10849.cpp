#include <cstdio>

int main(void){
	int d11, d12, d21, d22, moves, n, t, x1, x2, y1, y2;
	for(scanf("%d", &t); t-- && scanf("%d %*d", &n) == 1; ){
		while(n-- && scanf("%d%d%d%d", &x1, &y1, &x2, &y2) == 4){
			d11 = x1 + y1, d12 = x1 - y1;
			d21 = x2 + y2, d22 = x2 - y2;
			moves = 2 - (d11 == d21) - (d12 == d22);
			if((d11 & 1) != (d21 & 1) || (d12 & 1) != (d22 & 1)) puts("no move");
			else printf("%d\n", moves);
		}
	}
	return 0;
}

