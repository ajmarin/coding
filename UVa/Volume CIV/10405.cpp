/////////////////////////////////
// 10405 - Longest Common Subsequence
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define MAX(a,b) (a<b?b:a)
int m,n,i,j;
char s[1005],t[1005];
int lcs[1001][1001];
int main(void){
	while(gets(s) && gets(t)){
		m = strlen(s);
		n = strlen(t);
		for(i = 0; i <= m; i++) lcs[i][0] = 0;
		for(j = 0; j <= n; j++) lcs[0][j] = 0;
		for(i = 1; i <= m; i++)
			for(j = 1; j <= n; j++)
				if(s[i-1] == t[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
				else lcs[i][j] = MAX(lcs[i-1][j],lcs[i][j-1]);
		printf("%d\n",lcs[m][n]);
	}
	return 0;
}
