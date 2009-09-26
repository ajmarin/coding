#include <cstdio>
int tv[1024][1024];
int main(void){
	int i, j, lsc, lsl, m, n, x, y;
	for(int t = 1; scanf("%d%d",&m,&n) && m; t++){
		x = y = 0;
		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
				scanf("%d",&tv[i][j]);
		while(scanf("%d%d",&i,&j) && (i||j))
			x -= i, y += j;
		if(x < 0){
			if((-x) % n == 0) x = 0;
			else x = x + (-x/n + 1)*n;
		} else x %= n;
		if(y < 0){
			if((-y) % m == 0) y = 0;
			else y = y + (-y/m + 1)*m;
		} else y %= m;
		lsl = (m+y); lsc = (n+x);
		printf("Teste %d\n",t);
		for(i = y; i < lsl; putchar('\n'), i++)
			for(j = x;  j < lsc; j++)
				printf("%d ",tv[i%m][j%n]);
		putchar('\n');
	}
	return  0;
}
