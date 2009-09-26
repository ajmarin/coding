#include <cstdio>
int main(void){
	int a, b, dep, diff, teste = 1;
	while(scanf("%d",&dep) && dep){
		diff = 0;
		printf("Teste %d\n",teste++);
		while(dep--){
			scanf("%d%d",&a,&b);
			diff = diff + (a - b);
			printf("%d\n",diff);
		}
		putchar('\n');
	}
	return 0;
}