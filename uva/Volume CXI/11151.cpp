#include <cstdio>
#include <cstring>

#define FOR(i,n) for(int i = 0; i < n; ++i)
char text[1024];
int dp[1024][1024];

int max(int a, int b){ return a > b ? a : b; }

int z(int l, int r){
	if(l > r) return dp[l][r] = 0;
	if(l == r) return dp[l][r] = 1;
	if(dp[l][r] != -1) return dp[l][r];
	if(text[l] == text[r]) return dp[l][r] = z(l + 1, r - 1) + 2;
	return dp[l][r] = max(z(l + 1, r), z(l, r - 1));
}

int main(void){
	int len, t; scanf("%d", &t); getchar();
	while(t-- && gets(text)){
		len = strlen(text);
		FOR(i, len) FOR(j, len) dp[i][j] = -1;
		printf("%d\n", z(0, len - 1));
	}
	return 0;
}

