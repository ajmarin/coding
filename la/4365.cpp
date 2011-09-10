#include <cstdio>

int main(void){
	int dp[11][11];
	for(int i = 0; i < 11; ++i) for(int j = 0; j < 11; ++j)
		dp[i][j] = (i ? dp[i - 1][j] : 0) + (j ? dp[i][j - 1] : 0) + (!i && !j);
	for(int a, b; scanf("%d %d", &a, &b) == 2 && a >= 0; )
		if(dp[a][b] == a + b) printf("%d+%d=%d\n", a, b, a + b);
		else printf("%d+%d!=%d\n", a, b, a + b);
	return 0;
}

