#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;
#define FOR(i,e)	for(int i = 0; i < e; ++i)
#define FORE(i,s,e)	for(typeof(s) i = s; i != e; ++i)
#define FORI(i,s,e)	for(int i = s; i < e; ++i)
#define PB			push_back
const int N = 300048;
int r[N], n, sh = 0, s[N];
bool L[N];
vi x, y, z;
void ssv(vi t){
	sort(t.begin(), t.end()); int sz = t.size();
	FOR(i, sz) printf("%d%c", t[i], ++sh == n ? '\n': ' ');
}
int main(void){
	int t; scanf("%d", &n); n *= 3;
	FOR(i,n) scanf("%d", &t), r[t] = i, L[i] = 0; L[n] = L[n+1] = 0;
	FOR(i,n) {
		scanf("%d", &s[i]);
		if(i % 3 == 2){
			int c = s[i];
			if(r[s[i - 1]] < r[c]) c = s[i - 1];
			if(r[s[i - 2]] < r[c]) c = s[i - 2];
			L[c] = 1;
		}
	}
	scanf("%d", &t);
	if(!L[t]) FORI(i, 1, n + 1){
		if(i == t) continue;
		printf("%d%c", i, ++sh == n ? '\n': ' ', i);
	} else {
		int a[3], b;
		for(b = 0; s[b] != t; ++b);
		b = (b / 3) * 3;
		FOR(i, 3) a[i] = s[b + i] == t ? N : s[b + i];
		sort(a, a+3);
		FOR(i, b){
			if(s[i] < a[0]) x.PB(s[i]);
			else if(s[i] < a[1]) y.PB(s[i]);
			else z.PB(s[i]);
		}
		x.PB(a[0]);
		y.PB(a[1]);
		FORI(i, b + 3, n) z.PB(s[i]);
		ssv(x); ssv(y); ssv(z);
	}
	return 0;
}
