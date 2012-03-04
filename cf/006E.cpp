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

const int N = 100048;
int h[N], r[N];
int main(void){
	int a = 0, c, n, k; scanf("%d %d", &n, &k);
	multiset < int > s;
	FOR(i, n) scanf("%d", h + i);
	for(int i = 0, b = 0; i < n; ++i){
		s.insert(h[i]);
		while(*s.rbegin() - *s.begin() > k) s.erase(s.find(h[b++]));
		if(i - b + 1 > a) a = i - b + 1, r[(c = 0)++] = b;
		else if(i - b + 1 == a) r[c++] = b;
	}
	printf("%d %d\n", a, c);
	FOR(i, c) printf("%d %d\n", r[i] + 1, r[i] + a);
	return 0;
}

