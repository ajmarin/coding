/////////////////////////////////
// 10066 - The Twin Towers
/////////////////////////////////
#include<cstdio>
char i,j,m,n;
unsigned int t_first[100],t_sec[100];
char lcs[101][101];
unsigned int cnum = 0;
int main(void){
	while(scanf("%u %u",&m,&n) && (m||n)){
		cnum++;
		for(i = 0; i < m; i++) scanf("%u",&t_first[i]);
		for(j = 0; j < n; j++) scanf("%u",&t_sec[j]);
		m++; n++;	
		for(i = 0; i < m; i++) lcs[i][0] = 0;
		for(j = 0; j < n; j++) lcs[0][j] = 0;
		for(i = 1; i < m; i++){
			for(j = 1; j < n; j++)
				if(t_first[i-1] == t_sec[j-1])
					lcs[i][j] = lcs[i-1][j-1]+1;
				else if(lcs[i][j-1]>lcs[i-1][j])
					lcs[i][j] = lcs[i][j-1];
				else
					lcs[i][j] = lcs[i-1][j];
		}
		printf("Twin Towers #%u\nNumber of Tiles : %u\n\n",
		cnum,lcs[m-1][n-1]);
	}	
	return 0;
}

