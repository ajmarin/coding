#include <cstdio>
#define max(a,b) ((a>b)?(a):(b))
int main(void){
	int COMP, FRAS, i, j;
	int c[51], d[51], m[51][1001];
	for(int t = 1; scanf("%d%d",&COMP,&FRAS) && COMP; t++){
		for(i = 1; i <= FRAS; i++)
			scanf("%d%d",&c[i],&d[i]);

		for(i = 0; i <= COMP; i++) m[0][i] = 0;
		for(i = 1; i <= FRAS; i++){
			m[i][0] = 0;
			for(j = 1; j <= COMP; j++){
				if(c[i] > j) m[i][j] = m[i-1][j];
				else {
					int temp = m[i-1][j-c[i]]+d[i];
					m[i][j] = max(temp,m[i-1][j]);
				}
			}
		}
		printf("Teste %d\n%d\n\n",t,m[FRAS][COMP]);
	}
	return 0;
}

