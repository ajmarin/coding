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

int main(void){
	int b, h, num;
	char dir[64];
	scanf("%d %d", &b, &h);
	int l = 1, r = b + 1;
	for(int i = 0; i < h; ++i){
		scanf("%*s %*s %s %*s %d", dir, &num);
		if(dir[0] == 'l'){
			if(num <= r) r = num;
		} else if(num + 1 >= l) l = num + 1;
	}
	printf("%d\n", r > l ? r - l : -1);
	return 0;
}

