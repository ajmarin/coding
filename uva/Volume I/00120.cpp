/////////////////////////////////
// 00120 - Stacks of Flapjacks
/////////////////////////////////
#include<cstdio>
#include<algorithm>
int i,j,pancakes,temp;
int normal[30];
int order[30];
char c;
bool ordered(void){
	for(int ord = 0; ord < pancakes; ord++) if(normal[ord] != order[ord]) return 0;
	return 1;
}
int main(void){
	while(scanf("%d%c",&normal[0],&c)!=EOF){
		printf("%d",normal[0]);
		order[0] = normal[0];
		for(i = 1; c != '\n';order[i] = normal[i],i++)
			scanf("%d%c",&normal[i],&c);
		pancakes = i;
		std::sort(order,order+pancakes);		
		for(i = 1; i < pancakes; i++) printf(" %d",normal[i]);
		putchar('\n');
		for(i = 0;!ordered();i++){
			if(normal[0] != order[pancakes-i-1]){				
				for(j = 0; normal[pancakes-j-1] != order[pancakes-i-1]; j++);
				printf("%d ",j+1);
				std::reverse(normal,normal+pancakes-j);
			}
			printf("%d ",i+1);
			std::reverse(normal,normal+pancakes-i);
		}
		printf("0\n");
	}
}
