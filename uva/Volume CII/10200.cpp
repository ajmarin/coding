#include <cmath>
#include <cstdio>

int cnt[10001];
bool prime(int x){
	if(!(x & 1) || !(x % 3)) return false;
	for(int i = 6, t1 = 0, t2; t1 * t1 <= x; i += 6){
		t1 = i - 1;
		t2 = i + 1;
		if(!(x % t1) || !(x % t2)) return false;
		if(t1 * t1 > x) break;
	}
	return true;
}

int main(void){
	cnt[0] = 1;
	for(int i = 1; i < 10001; ++i) cnt[i] = cnt[i - 1] + prime(i*i + i + 41);
	for(int ans, a, b, c; scanf("%d%d", &a, &b) == 2; ){
		c = b - a + 1;
		ans = (10000 * (cnt[b] - cnt[a - 1]) + c/2) / c;
		printf("%d.%02d\n", ans / 100, ans % 100);
	}
	return 0;
}

