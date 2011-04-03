#include <algorithm>
#include <cstdio>
using namespace std;
struct segment {
	int dp, i, l, p, r;
	bool fits_in(segment& s){
		return l > s.l && r < s.r;
	}
	bool operator<(const segment& s) const {
		return l < s.l || (l == s.l && r > s.r);
	}
} s[512];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int idx, maxl = 0;
		for(int i = 0; i < n; ++i){
			s[i].dp = 1;
			s[i].i = i+1;
			s[i].p = -1;
			scanf("%d %d", &s[i].l, &s[i].r);
		}
		sort(s, s + n);
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j)
				if(s[i].fits_in(s[j]) && s[i].dp < s[j].dp + 1){
					s[i].dp = s[j].dp + 1;
					s[i].p = j;
				}
			if(s[i].dp > maxl){
				maxl = s[i].dp;
				idx = i;
			}
		}
		printf("%d\n", s[idx].dp);
		for(; idx != -1; idx = s[idx].p)
			printf("%d%c", s[idx].i, s[idx].p == -1 ? 10 : 32);
	}
	return 0;
}

