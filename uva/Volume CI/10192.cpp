/////////////////////////////////
// 10192 - Vacation
/////////////////////////////////
#include<cstdio>
#include<cstring>
char i,j,m,n;
char c1[105],c2[105];
char lcs[101][101];
bool v[128];
unsigned int cnum = 0;
int main(void){
	while(gets(c1) && c1[0] != '#'){
		cnum++;
		gets(c2);
		m = strlen(c1);
		n = strlen(c2);
		memset(v,0,sizeof(v));
		for(i = 0; i <= m; i++) lcs[i][0] = 0;
		for(j = 0; j <= n; j++) lcs[0][j] = 0;
		for(i = 1; i <= m; i++){
			for(j = 1; j <= n; j++)
				if(c1[i-1] == c2[j-1] && !v[c1[i-1]])
					lcs[i][j] = lcs[i-1][j-1]+1;
				else if(lcs[i][j-1]>lcs[i-1][j])
					lcs[i][j] = lcs[i][j-1];
				else
					lcs[i][j] = lcs[i-1][j];
		}
		printf("Case #%u: you can visit at most %u cities.\n",
		cnum,lcs[m][n]);
	}	
	return 0;
}

