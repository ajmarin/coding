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
int adj[128][128], n;
bool v[128];
int dfs(int x, int f){
	int r = 0;
	FOR(i, n) if(i != f && adj[x][i] && !v[i]){
		if(adj[x][i] < 0) r += -adj[x][i];
		v[i] = 1;
		r += dfs(i, x);
	}
	return r;
}
int main(void){
	int a, b, c = 0, r, w; scanf("%d", &n);
	FOR(i, n) FOR(j, n) adj[i][j] = 0;
	FOR(i, n){
		scanf("%d %d %d", &a, &b, &w); --a; --b;
		v[i] = 0;
		c += w;
		adj[a][b] = w;
		adj[b][a] = -w;
	}
	r = dfs(0, -1);	
	printf("%d\n", MIN(r, c - r));
	return 0;
}

