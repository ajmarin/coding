#include <cstdio>

const int MAX = 200001, ROOT = 449;

bool p[MAX];
long long cnt[MAX];

int gcd(int a, int b){ return b ? gcd(b, a % b) : a; }

int main(void){
	p[0] = p[1] = false;
	cnt[0] = 0; cnt[1] = 2;
	for(int i = 2; i < MAX; ++i){
		p[i] = true;
		cnt[i] = i;
	}
	for(int i = 2; i < MAX; ++i) if(p[i]){
		--cnt[i];
		for(int j = i << 1; j < MAX; j += i){
			p[j] = false;
			cnt[j] = (cnt[j] / i) * (i - 1);
		}
	}
	for(int i = 2; i < MAX; ++i) cnt[i] += cnt[i - 1];
	for(long long n; scanf("%lld", &n) == 1 && n; ){
		int ans = 0, l = 0, m, r = MAX;
		while(l < r){
			m = (l + r) >> 1;
			if(cnt[m] < n) l = m + 1;
			else r = m;
		}
		for(long long i = cnt[l - 1]; i < n; ++ans){
			while(gcd(ans, l) != 1) ++ans;
			if(++i == n) break;
		}
		printf("%d/%d\n", ans, r);
	}
	return 0;
}

