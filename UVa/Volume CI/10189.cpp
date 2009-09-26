/////////////////////////////////
// 10189 - Minesweeper
/////////////////////////////////
#include<cstdio>
#define MAX 100
int i,j,x,y,field = 0;
char line[105];
bool posi,posj,limi,limj;
int m[MAX][MAX];
void analyze(){	
	for(i = 0; i < x; i++)
		for(j = 0; j < y; j++)
			if(m[i][j] > 10){
				posi = i > 0;
				posj = j > 0;
				limi = i < x-1;
				limj = j < y-1;
				if(posi){
					m[i-1][j]++;
					if(posj) m[i-1][j-1]++;
					if(limj) m[i-1][j+1]++;
				}
				if(posj) m[i][j-1]++;
				if(limj) m[i][j+1]++;				
				if(limi){
					m[i+1][j]++;
					if(posj) m[i+1][j-1]++;
					if(limj) m[i+1][j+1]++;
				}				
			}
		
}
int main(void){
	while(true){
		scanf("%d %d",&x,&y);
		if(x==y && y==0) break;
		if(field) printf("\n");
		printf("Field #%d:\n",++field);		
		for(i = 0; i < x; i++){
			scanf("%s",&line);
			for(j = 0; j < y; j++){
				if(line[j] == '*')m[i][j] = 15;
				else m[i][j] = 0;
			}
		}
		analyze();
		for(i = 0; i < x; i++){
			for(j = 0; j < y; j++){
				if(m[i][j] < 10) printf("%d",m[i][j]);
				else printf("*");
			}
			printf("\n");
		}
	}
}
