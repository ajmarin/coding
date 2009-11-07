#include <cstdio>
int main(void){
	int a, b, n, tnum = 1, v1, v2;
	while(scanf("%d",&n) && n){
		a = b = 0;
		printf("Teste %d\n",tnum++);
		while(n--){
			scanf("%d%d",&v1,&v2);
			a += v1; b += v2;
		}
		if(a > b) puts("Aldo\n");
		else puts("Beto\n");
	}
	return 0;
}