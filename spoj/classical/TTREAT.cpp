#include <cstdio>

struct interval {
	int b, e;
	bool intersect(interval &i){ return !(b >= i.e || e <= i.b); }
} d[10048];
int main(void){
	for(int cnt, i, j, m, n; scanf("%d %d", &n, &m) && (n || m); ){
		for(i = 0; i < n; ++i){ scanf("%*d %*d %d %d", &d[i].b, &d[i].e); d[i].e += d[i].b; }
		for(i = 0; i < m; ++i){
			scanf("%d %d", &d[n].b, &d[n].e); d[n].e += d[n].b;
			for(cnt = j = 0; j < n; ++j) cnt += d[j].intersect(d[n]);
			printf("%d\n", cnt);
		}
	}
	return 0;
}

