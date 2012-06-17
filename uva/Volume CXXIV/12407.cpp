#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i, n) for(int i = 0; i < n; ++i)

double s[128], x[128];
int main(void){
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		int n, d;
		double l, h = 1e10, m, sum;
		scanf("%d %d", &n, &d);
		FOR(i, n){
			scanf("%lf", s + i);
			h = min(h, 1.0 / s[i]);
		}
		l = -h;
		FOR(i, 50){
			sum = 0;
			m = (l + h) * .5;
			FOR(j, n) sum += x[j] = (100 * m * s[j]) / sqrt(1 - m * m * s[j] * s[j]);
			if(sum < d) l = m;
			else h = m;
		}
		
		double ans = 0;
		FOR(i, n) ans += sqrt(10000.0 + x[i] * x[i]) / s[i];
		printf("Case %d: %.8lf\n", c, ans);
	}


	return 0;
}

