#include <cmath>
#include <cstdio>

int main(void){
	int cases;
	for(scanf("%d", &cases); cases--; ){
		int n, k;
		double p;
		scanf("%d %lf %d", &n, &p, &k);
		printf("%.4lf\n", p ? pow(1.0 - p, k - 1) * p / (1 - pow(1.0 - p, n)) : 0);
	}
	return 0;
}

