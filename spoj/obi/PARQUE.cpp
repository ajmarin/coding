#include <cstdio>
#include <cstring>
#define MIN(a,b) ((a<b)?(a):(b))
int main(void){
	char ans[210], w1[105], w2[105];
	int i, j, l1, l2, ll, LCS[110][110];
	for(int t = 1; gets(w1+1) && w1[1] != '#'; t++){
		gets(w2+1);
		l1 = strlen(w1+1), l2 = strlen(w2+1);
		for(i = 0; i <= l1 || i <= l2; i++)	LCS[i][0] = LCS[0][i] = i;
		for(i = 1; i <= l1; i++)
			for(j = 1; j <= l2; j++)
				if(w1[i] == w2[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
				else LCS[i][j] = MIN(LCS[i-1][j],LCS[i][j-1]) + 1;
		ll = LCS[--i][--j];
		ans[ll] = 0;
		while(ll--)
			if(i && j && w1[i] == w2[j]) ans[ll] = w1[i], i--, j--;
			else if(i && LCS[i][j] == LCS[i-1][j]+1) ans[ll] = w1[i--];
			else ans[ll] = w2[j--];		
		printf("Teste %d\n%s\n\n",t,ans);
	}
	return 0;
}
