#include <algorithm>
#include <cstdio>
using namespace std;
struct interval {
	int l, r;
	bool operator<(interval x) const {
		return l < x.l || (l == x.l && r < x.r);
	}
} v[100048];
int idx[100048];
int main(void){
	int c, k, l, m, r, t;
	for(scanf("%d", &t); t-- && scanf("%d", &m) == 1;){
		for(c = 0; scanf("%d %d", &v[c].l, &v[c].r) && (v[c].l || v[c].r); c++);
		sort(v, v + c);
		k = l = r = 0;
		for(int i = 0; i < c && r < m; k++){
			if(v[i].l > l) i++;
			for(; i < c && v[i].l <= l; ++i)
				if(v[i].r >= r){
					r = v[i].r;
					idx[k] = i;
				}
			l = r;
		}
		if(r < m) puts("0");
		else {
			printf("%d\n", k);
			for(int *p = idx; p < (idx + k); ++p) printf("%d %d\n", v[*p].l, v[*p].r);
		}
		if(t) putc(10, stdout);
	}
	return 0;
}

