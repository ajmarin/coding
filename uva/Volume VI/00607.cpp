#include <cstdio>

const int INF = 1<<30, NN = 1024;
int dp[NN][NN];
int mb[NN], t[NN];

int min(int a, int b){ return a < b ? a : b; }

int f(int x, int C){
	if(!x) return 0;
	if(x <= 10) return -C;
	return (x - 10) * (x - 10);
}

int main(void){
	mb[0] = t[0] = 0;
	for(int cn = 0, n; scanf("%d", &n) == 1 && n; ){
		int L, C;
		if(cn) puts("");
		scanf("%d %d", &L, &C);
		for(int i = 1, j = 0; i <= n; ++i){
			scanf("%d", t + i);
			t[i] += t[i - 1];
			while(t[i] - t[j] > L) ++j; 
			mb[i] = j;
		}
		int ans = 1;
		for(int i = 1, j = 0; i <= n; ++i)
			if(t[i] - t[j] > L){
				j = i - 1;
				++ans;
			}

		for(int i = 0; i <= ans; ++i)
			for(int j = 0; j <= n; ++j)
				dp[i][j] = INF;

		dp[0][0] = 0;

		for(int lecture = 0; lecture < ans; ++lecture)
			for(int topic = 0; topic < n; ++topic) if(dp[lecture][topic] < INF)
				for(int e = topic + 1; e <= n && mb[e] <= topic; ++e)
					dp[lecture + 1][e] = min(dp[lecture + 1][e],
						dp[lecture][topic] + f(L - t[e] + t[topic], C));

		printf("Case %d:\nMinimum number of lectures: %d\n", ++cn, ans);
		printf("Total dissatisfaction index: %d\n", dp[ans][n]);
	}

	return 0;
}

