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

char word[128];
bool need[128];
int main(void){
	int l, m, n; scanf("%d %s", &n, word);
	char put = 'a' + n - 1;
	bool ok = true;
	l = strlen(word);
	FORI(c, 'a', 'a' + n) need[c] = 1;
	FOR(i, l) need[word[i]] = 0;
	for(int m = (l-1)>>1; m > -1; --m){
		int r = l - m - 1;
		if(word[m] == '?'){
			if(word[r] == '?'){
				while(put > 'a' && !need[put]) put--;
				word[m] = word[r] = put;
				need[put] = 0;
				if(put > 'a') put--;
			} else word[m] = word[r];
		} else if(word[r] == '?') word[r] = word[m];
		else ok &= word[m] == word[r];
		ok &= word[m] < 'a' + n;
		ok &= word[r] < 'a' + n;
	}
	FORI(c, 'a', 'a' + n) ok &= !need[c];
	puts(ok ? word : "IMPOSSIBLE");
	return 0;
}
