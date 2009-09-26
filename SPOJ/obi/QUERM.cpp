#include<cstdio>
#include<cstring>
#include<cstdlib>
char line[90000];
int main(void){
	int n;
	for(int a = 1, n; scanf("%d\n",&n) && n; a++){
		gets(line);		
		char *ptr = strtok(line," ");
		int i = 0;
		while(ptr!=NULL){
			int k = atoi(ptr);
			if(k == ++i) break;
			ptr = strtok(NULL," ");
		}
		printf("Teste %d\n%d\n\n",a,i);
	}
	return 0;
}