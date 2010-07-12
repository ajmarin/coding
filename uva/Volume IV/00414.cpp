/////////////////////////////////
// 00414 - Machined Surfaces
/////////////////////////////////
#include<cstdio>
char line[30];
unsigned int i,J,K,min_blanks,n,sum;

int main(void){
	while(scanf("%u\n",&n) && n){
		min_blanks = 23; sum = 0;
		for(i = 0; i != n; i++){
			gets(line);
			for(J = 0; line[J] == 'X'; J++);
			for(K = 24; K>=J && line[K] == 'X'; K--);
			sum += (K-J+1);
			if(K+1-J < min_blanks) min_blanks = K-J+1;
		}
		sum -= min_blanks*n;
		printf("%u\n",sum);
	}
	return 0;
}
	
