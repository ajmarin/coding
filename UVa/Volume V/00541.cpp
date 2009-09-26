/////////////////////////////////
// 00541 - Error Correction
/////////////////////////////////
#include<cstdio>
#define MAX 100
int i,j,N,cs,line,col;
bool corrupt;
bool m[MAX][MAX];
int main(void){
	scanf("%d",&N);
	while(N){
		line = col = -1;
		corrupt = cs = 0;
		for(i = 0; i < N; cs = 0,i++){
			for(j = 0; j < N; scanf("%d",&m[i][j]),cs+=m[i][j],j++);	
			if(cs%2)
				if(line == -1) line = i;
				else corrupt = true;			
		}
		if(!corrupt)
			for(cs = 0,i = 0; i < N; cs = 0,i++){
				for(j = 0; j < N; cs+=m[j][i],j++);
				if(cs%2)
					if(col == -1) col = i;
					else {
						corrupt = true;			
						break;
					}
			}
		if(corrupt) printf("Corrupt\n");
		else if(line == col && col == -1) printf("OK\n");
		else printf("Change bit (%d,%d)\n",line+1,col+1);
						
		scanf("%d",&N);
	}
	return 0;	
}
