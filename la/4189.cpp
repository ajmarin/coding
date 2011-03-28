#include <algorithm>
#include <cassert>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;
typedef long long LL;
const LL N = 1000000000000LL;
LL lucky[1 << 13];
set < LL > very;
vector < LL > vvery;
int lc = 0, vc = 0;
void dfs(LL k){
	if(k > N) return;
	if(k){ lucky[lc++] = k; }
	dfs(k*10 + 4);
	dfs(k*10 + 7);
}
void bt(LL k, int idx){
	if(k > 1){
		int sz = very.size();
		very.insert(k);
		if(very.size() == sz) return;
	}
	LL lim = N / k;
	for(int i = idx; lucky[i] <= lim && i < lc; ++i)
		bt(k * lucky[i], i);
}
int main(void){
	int t; scanf("%d", &t);
	dfs(0);
	sort(lucky, lucky + lc);
	bt(1, 0);
	vector < LL > vvery(very.begin(), very.end());
	vector < LL >::iterator bgn = vvery.begin(), end = vvery.end();
	while(t--){
		long long a, b;
		scanf("%lld %lld", &a, &b);
		printf("%d\n", upper_bound(bgn, end, b) - lower_bound(bgn, end, a));
	}
	return 0;
}

