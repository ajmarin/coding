#include <cstdio>

#define FOR(i,n) for(int i = 0; i < n; ++i)
#define FORI(i,s,n) for(int i = s; i < n; ++i)
#define T(i) (i & 0xFFF00000)
#define V(i) (i & 0x000FFFFF)

const int MAXB = 5051, MAXN = 101;
int b[MAXN], dp[MAXN][MAXB], t[MAXN], T = 1 << 20;

int min(int a, int b){ return a < b ? a : b; }

void set_min(int &x, int nv){
	if(T(x) == T) x = min(x, nv);
	else x = nv;
}

int main(void){
	FOR(j, MAXB) dp[0][j] = dp[1][j] = -1;
	for(int n; scanf("%d", &n) == 1 && n; T += (1 << 20)){
		int ans = 1 << 20, high = 1, low = 0;
		FOR(i,n) scanf("%d %d", t + i, b + i);
		dp[0][0] = T;
		FOR(i,n) {
			FORI(j, low, high) if(T(dp[i][j]) == T){
				set_min(dp[i + 1][j + b[i]], dp[i][j] + t[i]);
				if(j) set_min(dp[i + 1][j + b[i] - 1], dp[i][j] + (t[i] >> 1));
			}
			low += b[i] - (low > 0);
			high += b[i];
		}
		FOR(j, high) if(T(dp[n][j]) == T) ans = min(ans, V(dp[n][j]));
		printf("%d\n", ans);
	}
	return 0;
}

