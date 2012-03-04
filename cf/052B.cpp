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
const int N = 1024;
char board[N][N];
int CC[N], CL[N];
int main(void){
	long long c = 0;
	int n, m; scanf("%d %d", &n, &m);
	FOR(i, MAX(n,m)) CL[i] = CC[i] = 0;
	FOR(i, n){
		scanf("%s", board[i]);
		FOR(j, m) if(board[i][j] == '*') ++CL[i], ++CC[j];
	}
	FOR(i, n) FOR(j, m) if(board[i][j] == '*')
		c += 1LL * (CL[i] - 1) * (CC[j] - 1);
	printf("%lld\n", c);
	return 0;
}

