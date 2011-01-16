#include <cstdio>

int n, t, npontos, temp;
char nome[32];

int main(void) {
	while(scanf("%d %d",&t,&n)) {
		if(n == 0 && t == 0) break;
		npontos = 0;
		for(int i=0;i < t; i++) {
			scanf("%s %d",nome,&temp);
			npontos+=temp;
		}
		printf("%d\n",3*n-npontos);
	}
	return 0;
}

