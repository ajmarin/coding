#include <cstdio>
#define FOR(i,n)		for(int i = 0; i < n; ++i)
#define FORI(i,s,n)		for(int i = s; i < n; ++i)
#define FORIS(i,s,n,d)	for(int i = s; i < n; i += d)

const int MAXN = 2048, ROOT = 46;
const int NN = 1140, KK = 15, PP = 315;
bool prime[MAXN]; 
int p[MAXN/5], pc = 1;
int dp[KK][NN][PP];
int main(void){
	p[pc++] = 2;
	FOR(i, MAXN) prime[i] = i & 1;
	FORIS(i, 3, ROOT, 2) if(prime[i]) FORIS(j, i*i, MAXN, 2*i) prime[j] = false;
	FORIS(i, 3, MAXN, 2) if(prime[i]) p[pc++] = i;
	FOR(i, KK) FOR(j, NN) FOR(k, PP) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	FOR(i, KK - 1) FOR(j, NN) FOR(k, PP) if(dp[i][j][k]) 
		FORI(l, k + 1, PP){
			int new_sum = j + p[l];
			if(new_sum >= NN) break;
			dp[i+1][new_sum][l] += dp[i][j][k];
		}
	for(int n, k, w = 0; scanf("%d %d", &n, &k) == 2 && (n || k); w = 0){
		FOR(j, PP) w += dp[k][n][j];
		printf("%d\n", w);
	}
	return 0;
}

