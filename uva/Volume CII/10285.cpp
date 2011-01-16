/////////////////////////////////
// 10285 - Longest Run on a Snowboard
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define MAXS 32767
typedef unsigned int UI;
UI c, cnum, i, j, l[102][102], m[102][102], max_len, r;
char name[1024];
void go_down(UI len, UI x, UI y){
	if((l[x][y] = len)>max_len) max_len = len;	
	if(m[x-1][y]<m[x][y] && l[x-1][y]<len+1) go_down(len+1,x-1,y);
	if(m[x+1][y]<m[x][y] && l[x+1][y]<len+1) go_down(len+1,x+1,y);
	if(m[x][y-1]<m[x][y] && l[x][y-1]<len+1) go_down(len+1,x,y-1);
	if(m[x][y+1]<m[x][y] && l[x][y+1]<len+1) go_down(len+1,x,y+1);	
}
int main(void){
	for(i = 0; i < 102; i++) m[i][0]=m[0][i]=MAXS;
	scanf("%hu",&cnum);
	while(cnum--){
		scanf("%s%u%u",&name,&r,&c);
		r++; c++; max_len = 0; memset(l,0,sizeof(l));
		for(i = 1; i < r; i++)
			for(j = 1; j < c; j++)
				scanf("%u",&m[i][j]);
		for(i = 1; i < r; i++) m[i][c] = MAXS; //right border
		for(j = 1; j < c; j++) m[r][j] = MAXS; //down border
		for(i = 1; i < r; i++)
			for(j = 1; j < c; j++)
				if(!l[i][j]) go_down(1,i,j);
		printf("%s: %hu\n",name,max_len);
	}
	return 0;
}
