/////////////////////////////////
// 00111 - History Grading
/////////////////////////////////
#include<cstdio>
#define MAX(a,b) (a<b?b:a)
int events,i,j,idx;
int oford[20];
int stord[20];
int lcs[21][21];
int main(void){
	scanf("%d",&events);
	for(i = 1; i <= events; i++){
		scanf("%d",&idx);
		oford[idx-1] = i;
	}
	while(scanf("%d",&idx)!=EOF){
		stord[idx-1] = 1;		
		for(i = 2; i <= events; i++){
			scanf("%d",&idx);
			stord[idx-1] = i;
		}
		for(i = 0; i <= events; i++) lcs[i][0] = lcs[0][i] = 0;
		for(i = 1; i <= events; i++)
			for(j = 1; j <= events; j++)
				if(oford[i-1] == stord[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
				else lcs[i][j] = MAX(lcs[i-1][j],lcs[i][j-1]);
		printf("%d\n",lcs[events][events]);
	}
	return 0;
}
