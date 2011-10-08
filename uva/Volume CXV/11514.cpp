#include <cstdio>
#include <map>
#include <string>
using namespace std;

#define FORI(i,s,n) for(int i = s; i < n; ++i)
#define FOR(i,n)	for(int i = 0; i < n; ++i)

const int INF = 0x3FFFFFFF, NN = 1024;
int beat[NN][NN], dp[NN][NN];
int c[NN], d[NN], p[NN];
map < string, int > m;

int main(void){
	char power[128];
	int cnum = 0;
	FOR(i, NN) FOR(j, NN) beat[i][j] = -1, dp[i][j] = i ? INF : 0;
	for(int P, V, E; scanf("%d %d %d", &P, &V, &E) == 3 && (P || V || E); ){
		++cnum; ++P; ++V;
		// Init variables
		dp[0][0] = 0;
		m.clear();
		// Read input
		FORI(i, 1, P){
			scanf("%s %d %d", power, p + i, c + i);
			m[power] = i;
		}
		FORI(i, 1, V){
			scanf("%*s %d %[^,\n]", d + i, power);
			do { 
				int j = m[power];
				if(p[j] >= d[i]) beat[i][j] = cnum;
			} while(scanf(",%[^,\n]", power) == 1);
		}
		// Find solution via O(VP) DP
		FORI(i, 1, V) FORI(j, 1, P){
			dp[i][j] = dp[i][j - 1];
			if(beat[i][j] == cnum)
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + c[j]);
		}
		puts(dp[V - 1][P - 1] <= E ? "Yes" : "No");
	}
	return 0;
}

