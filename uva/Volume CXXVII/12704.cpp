#include <cmath>
#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(int r, x, y; t--; ){
		scanf("%d %d %d", &x, &y, &r);
		double s = r - sqrt(x * x + y * y);
		printf("%.2lf %.2lf\n", s, 2.0 * r - s);
	}
	return 0;
}

