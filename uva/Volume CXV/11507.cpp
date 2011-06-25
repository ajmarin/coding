/////////////////////////////////
// 11507 - Bender B. Rodriguez Problem
/////////////////////////////////
#include<cstdio>
int moves,i;
char m[100000][3];
char axis,sig;
void rot(char *c){
	if(axis == 'x'){
		axis = c[1];
		if(sig == '-'){
			if(c[0] == '-') sig = '+';
			else sig = '-';
		} else sig = c[0];
	}
	else {
		axis = 'x';
		if(sig == '-') sig = c[0];
		else {
			if(c[0] == '-') sig = '+';
			else sig = '-';
		}			
	}
	//printf("rot(%s) = %c%c\n",c,sig,axis);
}
int main(void){
	while(scanf("%d\n",&moves)){
		if(moves == 0) break;
		axis = 'x'; sig = '+';
		for(i = 0; i < moves-1; i++){
			scanf("%s",&m[i]);
			//printf("%s ",m[i]);
			if(m[i][0] == 'N') continue;
			if(axis == 'x' || axis == m[i][1]) rot(m[i]);
		}
		//printf("\n");
		printf("%c%c\n",sig,axis);
	}
	return 0;
}
