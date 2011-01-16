/////////////////////////////////
// 00118 - Mutant Flatworld Explorers
/////////////////////////////////
#include<cstdio>
#include<cstring>
typedef unsigned short int USI;
USI dir,i,M,N;
short int X,Y;
char cmd[105];
bool seed[51][51], lost;
char wdir[] = "ESWN";
void check(){
	if(X > M){
		X--;
		if(!seed[X][Y]) lost = seed[X][Y] = 1;
	} else if(X < 0){
		X++;
		if(!seed[X][Y]) lost = seed[X][Y] = 1;
		
	} else if(Y > N){
		Y--;
		if(!seed[X][Y]) lost = seed[X][Y] = 1;
	} else if(Y < 0){
		Y++;
		if(!seed[X][Y]) lost = seed[X][Y] = 1;
	}
}
int main(void){
	scanf("%u %u\n",&M,&N);
	memset(seed,0,sizeof(seed));
	while(scanf("%d %d %c\n",&X,&Y,&dir)==3){		
		switch(dir){
			case 'E': dir = 100; break;
			case 'S': dir = 101; break;
			case 'W': dir = 102; break;
			case 'N': dir = 103; break;
		}
		gets(cmd);
		for(lost = i = 0; cmd[i] && !lost; i++)
			switch(cmd[i]){
				case 'R': dir++; break;
				case 'L': dir--; break;
				case 'F':					
					switch(wdir[dir%4]){
						case 'E': X++;	break;
						case 'S': Y--; break;
						case 'N': Y++; break;
						case 'W': X--; break;
					}
					check();
					break;
			}
		printf("%d %d %c",X,Y,wdir[dir%4]);
		if(lost) puts(" LOST");
		else putchar('\n');
	}
	return 0;
}