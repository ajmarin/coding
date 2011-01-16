#include <cstdio>
#include <algorithm>
char c[5];
int main(void){
	int i, n; scanf("%d",&n);
	for(int t = 1; n--; t++){
		printf("Teste %d\n",t);
		scanf("%d%d%d%d%d",&c[0],&c[1],&c[2],&c[3],&c[4]);
		std::sort(c,c+5);
		bool yes = 1;
		for(i = 0; yes && i < 4; i++)
			yes = (c[i] == c[i+1] - 1);
		if(yes) printf("%d\n\n",200+c[0]);
		else if(c[0] == c[3] || c[1] == c[4])
			printf("%d\n\n",180+c[1]);
		else if((c[0] == c[2] && c[3] == c[4]) ||
			(c[0] == c[1] && c[2] == c[4]))
			printf("%d\n\n",160+c[2]);
		else if(c[0] == c[2] || c[1] == c[3] || c[2] == c[4])
			printf("%d\n\n",140+c[2]);
		else if((c[0] == c[1] && c[2] == c[3]) ||
				(c[0] == c[1] && c[3] == c[4]) ||
				(c[1] == c[2] && c[3] == c[4]))
			printf("%d\n\n",3*c[3]+(c[1]<<1)+20);
		else if(c[0] == c[1] || c[1] == c[2]) printf("%d\n\n",c[1]);
		else if(c[2] == c[3] || c[3] == c[4]) printf("%d\n\n",c[3]);
		else printf("0\n\n");
	}
	return 0;
}
