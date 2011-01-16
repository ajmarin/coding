/////////////////////////////////
// 00572 - Oil Deposits
/////////////////////////////////
#include<cstdio>
int i,j,m,n,pocket;
bool v[102][102];
char oil[102][102];
void visit(int x,int y){
	if(v[x][y]) return;
	v[x][y] = 1;
	if(oil[x][y] != '@') return;
	visit(x-1,y-1);
	visit(x-1,y+1);
	visit(x+1,y-1);
	visit(x+1,y+1);
	visit(x,y+1);
	visit(x,y-1);
	visit(x+1,y);
	visit(x-1,y);
}
int main(void){
	for(i = 0; i < 102; i++) for(j = 0; j < 102; j++) oil[i][j] = '-';
	while(scanf("%d %d\n",&m,&n) && m){
		for(i = 1; i <= m; getchar(),i++)
			for(j = 1; j <= n; v[i][j] = 0,j++)
				scanf("%c",&oil[i][j]);
		for(pocket = 0,i = 1; i <= m; i++)
			for(j = 1; j <=n ; j++)
				if(!v[i][j] && oil[i][j] == '@'){
					visit(i,j);
					pocket++;
				}
		printf("%d\n",pocket);
	}
	return 0;
}