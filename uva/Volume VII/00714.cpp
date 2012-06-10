#include <algorithm>
#include <cstdio>
using namespace std;

long long v[512], z[1024];
int main(void){
	int t; scanf("%d", &t);
	for(int k, n; t-- && scanf("%d %d", &k, &n) == 2; ){
		long long l = 0, m, r = 0, s;
		for(int i = 0; i < k; ++i){
			scanf("%lld", v + i);
			r += v[i];
			l = max(l, v[i]);
		}
		l = max(l, (r + k - 1) / k);
		while(l < r){
			int cnt = 1;
			m = (l + r) >> 1;
			s = 0;
			for(int i = k; i--; ) if(s + v[i] > m){ s = v[i]; ++cnt; } else s += v[i];
			if(cnt > n) l = m + 1;
			else r = m;
		}
		int h = s = 0, cnt = 1;
		for(int i = k; i--; ){
			if(s + v[i] > r || cnt + i < n) z[h++] = -1, s = 0, ++cnt;
			s += z[h++] = v[i];
		}
		while(h--){
			if(z[h] >= 0) printf("%lld%c", z[h], h ? 32 : 10);
			else printf("/ ");
		}
	}
	return 0;
}

