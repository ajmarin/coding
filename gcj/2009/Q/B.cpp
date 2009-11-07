#include <cstdio>
#include <cstring>

int L, C, k;
char map[100][100];
int m[100][100];
char chosen;
void dfs(int i, int j){
	int di = 0, dj = 0, diff = 0;
	if(i && m[i][j] - m[i-1][j] > diff){
		di = -1;
		dj = 0;
		diff = m[i][j] - m[i-1][j];
	}
	if(j && m[i][j] - m[i][j-1] > diff){
		di = 0;
		dj = -1;
		diff = m[i][j] - m[i][j-1];
	}
	if(j < (C-1) && m[i][j] - m[i][j+1] > diff){
		di = 0;
		dj = 1;
		diff = m[i][j] - m[i][j+1];
	}
	if(i < (L-1) && m[i][j] - m[i+1][j] > diff){
		di = 1;
		dj = 0;
		diff = m[i][j] - m[i+1][j];
	}
	if(di == dj && dj == 0){
		if(map[i][j]) chosen = map[i][j];
		else chosen = (k++)+'a';
	}
	else dfs(i+di,j+dj);
	map[i][j] = chosen;
}
int main(void){
	int i, j, N;
	scanf("%d",&N);
	for(int cnum = 1; cnum <= N; cnum++){
		scanf("%d%d",&L,&C);
		for(i = 0; i < L; i++)
			for(j = 0; j < C; j++)
				scanf("%d",&m[i][j]);
		memset(map,0,sizeof(map));
		for(k =i = 0; i < L; i++)
			for(j = 0; j < C; j++)
				if(!map[i][j]) dfs(i,j);
		printf("Case #%d:\n",cnum);
		for(i = 0; i < L; i++){
			putc(map[i][0],stdout);
			for(j = 1; j < C; j++){
				putc(' ',stdout);
				putc(map[i][j],stdout);
			}
			putc(10,stdout);
		}
	}	
	return 0;
}

