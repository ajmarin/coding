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

int main(void){
	int dep[3] = {0, 0, 0};
	int dl[3][3], dlc[3] = {0, 0, 0};
	int q[3], h = 0, t = 0;
	char ans[8];
	char a, b, c;
	FOR(i, 3){ 
		scanf("%c%c%c\n", &a, &c, &b);
		if(c == '>') a ^= b ^= a ^= b;
		a -= 'A'; b -= 'A';
		++dep[b];
		dl[a][dlc[a]++] = b;
	}
	FOR(i, 3) if(!dep[i]) q[t++] = i;
	while(h != t){
		int x = q[h];
		ans[h] = x + 'A';
		FOR(i, dlc[x]) if(!--dep[dl[x][i]]) q[t++] = dl[x][i];
		h++;
	}
	ans[3] = 0;
	if(h == 3) puts(ans);
	else puts("Impossible");
	return 0;
}
