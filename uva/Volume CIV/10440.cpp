#include <algorithm>
#include <cstdio>
using namespace std;
int v[4096];
int main(void){
	int act, c, m, n, t, tp;
	for(scanf("%d", &c); c-- && scanf("%d %d %d", &n, &t, &m) == 3; ){
		t <<= 1;
		act = tp = 0;
		for(int i = 0; i < m; ++i) scanf("%d", &v[i]);
		for(int i = (m + n - 1) % n; i < m; i += n) act = max(tp, v[i]), tp = act + t;
		printf("%d %d\n",  tp - (t >> 1), (m + n - 1)/n);
	}
	return 0;
}

