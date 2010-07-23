#include <algorithm>
#include <cstdio>

struct interval {
	int a, b;
	bool w;
	interval(int _a = 0, int _b = 0){ a = _a, b = _b; }
	bool operator<(const interval x) const {
		return a < x.a;
	}
} k[1024];

int main(void){	
	for(int ans, bt, cnum = 1, n; scanf("%d", &n) && n != -1; ++cnum){		
		for(int i = 0; i < n; ++i) scanf("%d %d", &k[i].a, &k[i].b), k[i].w = 0;
		ans = 0;
		std::sort(k, k + n);
		for(int i = 0; i < n; ++i){	
			if(k[i].w) continue;
			ans++;
			bt = k[i].b;
			for(int j = i + 1; j < n; ++j)
				if(!k[j].w && bt < k[j].a) k[j].w = 1, bt = k[j].b;		
		}
		printf("Case %d: %d\n", cnum, ans);
	}
	return 0;
}
