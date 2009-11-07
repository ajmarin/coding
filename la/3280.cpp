#include <cstdio>


char word[128][128];
int wsize[128];

void DOIT(int x, int y){
	int a = 0, b = 0;
	int i = 1;
	while(word[x][a] && word[y][b] && (word[x][a++] == word[y][b++])) i++;
	if(i > wsize[x]) wsize[x] = i;
	if(i > wsize[y]) wsize[y] = i;
}
int main(void){
	int cnum = 0, N, i, j;
	while(scanf("%d",&N) && N){
		for(i = 0; i < N; ++i){
			scanf("%s",&word[i]);
			j = 0;
			while(word[i][j]){
				if(word[i][j] <= 'Z') word[i][j] += 32;
				j++;
			}
			wsize[i] = 1;
			for(j = 0; j < i; ++j) DOIT(i,j);
		}
		printf("%d\n",++cnum);
		for(i = 0; i < N; ++i){
			printf("%s ",word[i]);
			word[i][wsize[i]] = 0;
			printf("%s\n",word[i]);
		}
	}
	return 0;
}
