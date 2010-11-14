#include <algorithm>
#include <cstdio>
using namespace std;
const char *ans[2] = {"IMPOSSIBLE", "POSSIBLE"};
int v[2048];
int main(void){
	bool ok;
	for(int n; scanf("%d", &n) == 1 && n; ){
		for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
		sort(v, v + n);
		ok = n > 6 && v[n - 1] >= 1322;
		for(int i = 1; ok && i < n; ++i) ok &= (v[i] - v[i - 1]) <= 200;
		puts(ans[ok]);
	}
	return 0;
}

