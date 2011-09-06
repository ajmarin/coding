#include <cstdio>

const int MAXC = 1024;
#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define IN getc(stdin)

char kb[32][32], line[MAXC], t[MAXC], w[MAXC];
int dp[MAXC][MAXC], dist[128][128];

int readLine(char *s){
	char c = IN;
	int read;
	if(c == EOF) return -1;
	for(read = 0; c != 10; *s++ = c, c = IN, ++read);
	*s = 0;
	return read;
}
int abs(int a){ return a < 0 ? -a : a; }
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	FOR(i, 128) dist[i][i] = 0;
	for(int n; readLine(line) != -1; ){
		if(sscanf(line, "%d", &n) != 1) break;
		int TOP, lt, lw, z;
		FOR(i, n) TOP = readLine(kb[i]);
		z = n * TOP;
		FOR(i, z) FORI(j, i + 1, z){
			int rI = i / TOP, rJ = j / TOP;
			int cI = i % TOP, cJ = j % TOP;
			char a = kb[rI][cI], b = kb[rJ][cJ];
			dist[a][b] = dist[b][a] = max(abs(rI - rJ), abs(cI - cJ));
		}
		TOP = max(TOP, n);
		lw = 1 + readLine(w+1);
		lt = 1 + readLine(t+1);
		dp[0][0] = 0;
		FORI(j, 1, lw) dp[0][j] = dp[0][j - 1] - TOP;
		FORI(i, 1, lt) FORI(j, 1, lw)
			dp[i][j] = max(dp[i][j - 1] - TOP, dp[i - 1][j - 1] + TOP - dist[t[i]][w[j]]);
		printf("%d\n", dp[lt-1][lw-1]);
	}
	return 0;
}

