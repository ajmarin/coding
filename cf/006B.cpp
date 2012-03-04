#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define FOR(i,e)		for(int i = 0; i < e; ++i)
#define FORD(i,s,e)		for(int i = s; i > e; --i)
#define FOREACH(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)		for(int i = s; i < e; ++i)
#define IN(x)			(x = getc(stdin))
#define OUT(x)			putc(x, stdout)
template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }
const int N = 128;
int ans = 0, n, m; 
char boss, office[N][N];
bool seen[N], v[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int x, int y){
	ans += !seen[office[x][y]];
	v[x][y] = seen[office[x][y]] = 1;
	if(office[x][y] != boss) return;
	FOR(d, 4){
		int nx = x + dx[d], ny = y + dy[d];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(!v[nx][ny] && office[nx][ny] != '.') dfs(nx, ny);
	}
}
int main(void){
	scanf("%d %d %c\n", &n, &m, &boss);
	FOR(i,128) seen[i] = 0;
	seen[boss] = 1;
	FOR(i,n) {
		fgets(office[i], N, stdin);
		memset(v[i], 0, m);
	}
	FOR(i,n) FOR(j, m) if(office[i][j] == boss){ dfs(i, j); break; }
	printf("%d\n", ans);
	return 0;
}

