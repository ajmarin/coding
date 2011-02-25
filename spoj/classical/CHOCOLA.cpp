#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1024;
int vm[N], vn[N];
int main(void){
	int ans, m, n, sm, sn, t;
	vm[0] = vn[0] = 0;
	for(scanf("%d", &t); t--; ){
		scanf("%d %d", &m, &n); ans = sm = sn = 0;
		for(int i = 1; i < m; ++i) scanf("%d", vm + i), sm += vm[i];
		for(int i = 1; i < n; ++i) scanf("%d", vn + i), sn += vn[i];
		sort(vm + 1, vm + m); sort(vn + 1, vn + n);
		--m; --n;
		while(m || n)
			if(vm[m] > vn[n]) ans += vm[m] + sn, sm -= vm[m--];
			else ans += vn[n] + sm, sn -= vn[n--];
		printf("%d\n", ans);
	}
	return 0;
}

