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
#define FOR(i,e)	for(int i = 0; i < e; ++i)
#define FORD(i,s,e)	for(int i = s; i > e; --i)
#define FORE(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)	for(int i = s; i < e; ++i)
#define IN(x)		(x = getc(stdin))
#define MP			make_pair
#define OUT(x)		putc(x, stdout)
#define PB			push_back
template <class _T> _T MAX(_T a, _T b){ return a > b ? a : b; }
template <class _T> _T MIN(_T a, _T b){ return a < b ? a : b; }
template <class _T> _T GCD(_T a, _T b){ return b ? gcd(b, a % b) : a; }

char f[16][16][16];
bool v[16][16][16];
int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};
int k, n, m, visited = 0;
void dfs(int z, int x, int y){
	visited++;
	v[z][x][y] = 1;
	for(int dir = 0; dir < 6; ++dir){
		int nx = x + dx[dir], ny = y + dy[dir], nz = z + dz[dir];
		if(nx < 1 || ny < 1 || nz < 1 || nx > n || ny > m || nz > k)
			continue;
		if(!v[nz][nx][ny] && f[nz][nx][ny] != '#') dfs(nz, nx, ny);
	}
}
int main(void){
	scanf("%d %d %d", &k, &n, &m);
	for(int i = 1; i <= k; ++i){
		for(int j = 1; j <= n; ++j){
			for(int l = 1; l <= m; ++l){
				char c = getc(stdin);
				while(c != '.' && c != '#') c = getc(stdin);
				f[i][j][l] = c;
				v[i][j][l] = 0;
			}
		}
	}
	int x, y;
	scanf("%d %d", &x, &y);
	dfs(1, x, y);
	printf("%d\n", visited);
	return 0;
}

