/////////////////////////////////
// 11067 - Little Red Riding Hood
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned int h, i, j, w, wnum;
bool nw[103][103];
unsigned int sol[103][103];
int main(void){
	for(i = 0; i < 103; i++) sol[i][0] = sol[0][i] = 0;
	while(scanf("%u%u",&w,&h) && w){
		scanf("%u",&wnum); ++w; ++h;
		memset(nw,1,sizeof(nw));
		while(wnum--) scanf("%u%u",&i,&j), nw[i+1][j+1] = 0;		
		sol[0][1] = nw[1][1];		
		for(i = 1; i <= w; i++)	for(j = 1; j <= h; j++)
			if(nw[i][j]) sol[i][j] = sol[i-1][j]+sol[i][j-1];
			else sol[i][j] = 0;
		if(sol[w][h]){
			if(sol[w][h]==1) printf("There is one path from Little Red Riding Hood's house to her grandmother's house.\n");
			else printf("There are %u paths from Little Red Riding Hood's house to her grandmother's house.\n",sol[w][h]);		
		} else printf("There is no path.\n");
	}
	return 0;
}

