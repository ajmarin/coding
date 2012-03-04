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

char bracket[50024];
priority_queue < pii > pq;
int main(void){
	scanf("%s", bracket);
	int a, b, open = 0;
	ll c = 0;
	for(int i = 0; bracket[i]; ++i){
		open = open + (bracket[i] == '(') - (bracket[i] != '(');
		if(bracket[i] == '?'){
			scanf("%d %d", &a, &b);
			bracket[i] = ')';
			pq.push(make_pair(-(a - b), i));
			c += b;
		}
		if(open < 0){
			if(pq.empty()) break;
			pii x = pq.top(); pq.pop();
			bracket[x.second] = '(';
			c += -x.first;
			open += 2;
		}
	}
	if(open != 0) puts("-1");
	else cout << c << endl << bracket << endl;
	return 0;
}

