#include <cstdio>
 
#define NN 65536
enum { LEFT, UP, RIGHT, DOWN };
 
int n, a, b, k, x, y;
int lado[NN];
 
int main(void) {
	int i, j, dir, cnt, ini;
	 
	scanf("%d", &n);
	 
	for(int cs = 1; cs <= n; cs++) {
		/* input */
		scanf("%d %d %d", &a, &b, &k);
		 
		/* preprocessa */
		dir = LEFT;
		cnt = ini = 1;
		j = 2;
		x = 0; y = 0;
		for(i = 0; i < NN; i++) {
			if(y == a*x + b) i--;
			else lado[i] = y < a*x + b;
			if(dir == LEFT) x--;
			if(dir == UP) y++;
			if(dir == RIGHT) x++;
			if(dir == DOWN) y--;
			if(!--cnt) {
				if(!--j) j = 2, ini++;
				cnt = ini;
				dir = (dir + 1) % 4;
			}
		}
		 
		/* consultas */
		printf("Caso %d\n", cs);
		while(k--) {
			scanf("%d %d", &x, &y);
			if(lado[x] == lado[y]) printf("Mesmo lado da fronteira\n");
			else printf("Lados opostos da fronteira\n");
		}
	}
	 
	return 0;
}

