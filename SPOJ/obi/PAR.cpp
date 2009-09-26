#include <cstdio>
int main(void){
	char name[2][15];
	int n, a, b, tnum = 1;
	while(scanf("%d",&n) && n){
		scanf("%s%s",&name[0],&name[1]);
		printf("Teste %d\n",tnum++);
		while(n--){			
			scanf("%d%d",&a,&b);
			puts(name[(a+b)&1]);
		}
		putchar('\n');
	}
	return 0;
}
