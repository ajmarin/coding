#include<cstdio>
int c, n, pares, v;
int main(void){
	while(scanf("%d",&n) && n){
		pares = 0;
		while(n--){
			scanf("%d%d",&c,&v);
			pares += (v>>1);
		}
		printf("%d\n",pares>>1);
	}
	return 0;
}
