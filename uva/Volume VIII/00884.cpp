#include <cstdio>

#define FORIS(i, s, n, d) for(int i = s; i < n; i += d)
const int MAXP = 1048576, ROOT = 1024;
bool p[MAXP];
int ans[MAXP], pl[MAXP/5], plc = 1;

void factors(int n, int idx, int cnt){
	if(n >= MAXP) return;
	ans[n] = cnt;
	int limit = MAXP / n;
	FORIS(i, idx, plc, 1){
		if(pl[i] > limit) break;
		factors(n * pl[i], i, cnt + 1);
	}
}
int main(void){
	pl[0] = 2;
	FORIS(i, 2, MAXP, 1) p[i] = i & 1, ans[i] = 1;
	FORIS(i, 3, ROOT, 2) if(p[i]) FORIS(j, i*i, MAXP, 2*i) p[j] = false;
	FORIS(i, 3, MAXP, 2) if(p[i]) pl[plc++] = i;
	factors(1, 0, 0);
	FORIS(i, 2, MAXP, 1) ans[i] += ans[i - 1];
	for(int n; scanf("%d", &n) == 1; printf("%d\n", ans[n]));
	return 0;
}

