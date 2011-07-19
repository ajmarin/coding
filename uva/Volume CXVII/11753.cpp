#include <cstdio>
#include <map>
#define MP make_pair
using namespace std;
const int MAXN = 10048;
map<pair<int, int>, int> m;
int ans, max_insertions;
int v[MAXN];
void r(int left, int right, int insertions){	
	if(insertions > max_insertions || left >= right){
		ans = min(ans, insertions);
		return;
	}
	int &x = m[MP(left, right)];
	if(!x || insertions < x){
		x = insertions;
		if(v[left] == v[right]) r(left + 1, right - 1, insertions);
		else {
			r(left, right - 1, insertions + 1);
			r(left + 1, right, insertions + 1);
		}
	}
}
int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0, n; cnum++ < t && scanf("%d %d", &n, &max_insertions) == 2; ){
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		m.clear();
		ans = max_insertions + 1;
		r(0, n-1, 0);
		printf("Case %d: ", cnum);
		if(ans == 0) puts("Too easy");
		else if(ans <= max_insertions) printf("%d\n", ans);
		else puts("Too difficult");
	}
	return 0;
}
