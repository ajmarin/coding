#include <algorithm>
#include <cstdio>
using namespace std;
#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define NN 301
long long dp[301][301];
char line[1024];
int main(void){
	FOR(i, NN) FOR(j, NN) dp[i][j] = 0;
	FOR(i, 301) dp[0][i] = 1;
	FORI(i, 1, 301) FORI(j, 1, 301){
		dp[i][j] = dp[i][j - 1];
		if(j <= i) dp[i][j] += dp[i - j][j];
	}
	while(fgets(line, 1024, stdin)){
		int l1, l2, n;
		if(sscanf(line, "%d %d %d", &n, &l1, &l2) == 3);
		else if(sscanf(line, "%d %d", &n, &l2) == 2) l1 = 0;
		else if(sscanf(line, "%d", &n) == 1) l1 = 0, l2 = n;
		l1 = min(300, l1);
		if(n == 0) puts("1");
		else printf("%lld\n", dp[n][min(300, l2)] - dp[n][l1 - (l1 != 0)]);
	}
	return 0;
}

