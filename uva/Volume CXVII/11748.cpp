#include <cstdio>
#define FOR(i, n)	for(int i = 0; i < n; ++i)
const int MAXN = 128;
int rank[MAXN][MAXN];
bool v[MAXN];
int m; // Number of voters
int n; // Number of candidates
bool wins(int a, int b){ // returns true if a beats b in an election
	int score = 0;
	FOR(i, m) score += rank[i][a] < rank[i][b];
	return score > m - score;
}
void dfs(int x){
	v[x] = 1;
	FOR(i, n) if(!v[i] && wins(x, i)) dfs(i);
}
int main(void){
	for(int w, z; scanf("%d %d %d", &n, &m, &w) && n; ){
		bool possible = true;
		FOR(i, n) v[i] = false;
		FOR(i, m) FOR(j, n) {
			scanf("%d", &z);
			rank[i][--z] = j;
		}
		dfs(--w);
		FOR(i, n) possible &= v[i];
		puts(possible ? "yes" : "no");
	}
	return 0;
}
