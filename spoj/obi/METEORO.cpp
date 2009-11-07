#include <cstdio>
int main(void){
	int c[4], meteor, hazard, teste = 1, x, y;
	while(scanf("%d%d%d%d",&c[0],&c[1],&c[2],&c[3])	
		&& (c[0] || c[1] || c[2] || c[3])){
		hazard = 0;
		scanf("%d",&meteor);
		while(meteor--){
			scanf("%d%d",&x,&y);
			if(x >= c[0] && x <= c[2] 
			&& y <= c[1] && y >= c[3])
				hazard++;
		}
		printf("Teste %d\n%d\n\n",teste++,hazard);
	}
	return 0;
}
