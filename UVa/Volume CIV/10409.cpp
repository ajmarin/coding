/////////////////////////////////
// 10409 - Die Game
/////////////////////////////////
#include<cstdio>
char cmd[30];
unsigned int i,n,nor,old,top,wes;

int main(void){
	while(scanf("%u\n",&n) && n){	
		top = 1; nor = 2; wes = 3;	
		for(i = 0; i != n; i++){
			gets(cmd);
			old = top;
			switch(cmd[0]){
				case 'n':
					top = 7-nor, nor = old; break;
				case 's':
					top = nor, nor = 7-old; break;
				case 'w':
					top = 7-wes, wes = old; break;
				default:
					top = wes, wes = 7-old; break;
			}
		}
		printf("%u\n",top);
	}
	return 0;
}
	
