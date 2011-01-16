/////////////////////////////////
// 10010 - Where's Waldorf?
/////////////////////////////////
#include<cstdio>
#include<cstring>
char board[52][52],i,j,m,n,word[250],words;
int len, found, cases;
void recsearch(int xo,int yo, int px, int py, int ax,int ay, int k){
	if(k == len) {
		printf("%d %d\n",xo,yo,word);
		found = true;
		return;
	}
	if(board[xo+ax][yo+ay] != word[k]) return;
	recsearch(xo,yo,px,py,ax+px,ay+py,k+1);
}
void search(void){
	char x,y;
	for(x = 1; x <= m; x++)
		for(y = 1; y <= n; y++)
			if(board[x][y] == word[0]){
				recsearch(x,y,0,1,0,1,1); // right
				if(!found) recsearch(x,y,1,0,1,0,1); // down
				if(!found) recsearch(x,y,0,-1,0,-1,1);// left
				if(!found) recsearch(x,y,-1,0,-1,0,1);// up
				if(!found) recsearch(x,y,1,1,1,1,1); // right down
				if(!found) recsearch(x,y,-1,1,-1,1,1); // right up
				if(!found) recsearch(x,y,1,-1,1,-1,1); // left down
				if(!found) recsearch(x,y,-1,-1,-1,-1,1); // left up
				if(found) return;
			}
}
int main(void){
	scanf("%d\n",&cases);
	while(cases--){
		scanf("%d %d\n",&m,&n);
		for(i = 0; i < m+2; i++) board[i][0] = '-';
		for(j = 0; j < n+2; j++) board[0][j] = board[m+1][j] = '-';
		for(i = 1; i <= m; i++) gets(board[i]+1);
		for(i = 0; i < m+2; i++) board[i][n+1] = '-';
		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				if(board[i][j] > 64 && board[i][j] < 91) board[i][j] +=32;
		scanf("%d\n",&words);
		while(words--){
			gets(word);
			found = false;
			len = strlen(word);
			for(j = 0; word[j] != '\0'; j++) if(word[j] > 64 && word[j] < 91) word[j] +=32;
			search();
		}
		if(cases) putchar('\n');
	}
	return 0;
}