/////////////////////////////////
// 00459 - Graph Connectivity
/////////////////////////////////
#include<cstdio>
#include<cstring>
bool g[26][26], v[26];
char conn, i, lim, x, y;
char line[5];
unsigned int cnum;
void dfs(char k){
	v[k] = 1;	
	for(char j = 0; j < lim; j++)
		if(g[k][j] && !v[j]) dfs(j);
}
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		gets(line);
		lim = line[0]-'A'+1;
		memset(g,0,sizeof(g));
		memset(v,0,sizeof(v));
		while(gets(line) && line[0])
			x = line[0]-'A', y = line[1]-'A',
			g[x][y] = g[y][x] = 1;
		for(conn = i = 0; i < lim; i++)
			if(!v[i]) dfs(i), conn++;
		printf("%u\n",conn);
		if(cnum) putchar('\n');
	}
	return 0;
}

