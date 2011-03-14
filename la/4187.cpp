#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
vector < double > x, y;
int main(void){
	for(int i, j, n; scanf("%d", &n) == 1 && n != 0; ){
		double xc, yc;
		x.clear(); y.clear();
		for(i = 0; i < n; ++i){
			scanf("%lf %lf", &xc, &yc);
			x.push_back(xc);
			y.push_back(yc);
		}
		if(n < 3){ puts("0"); continue; }
		double area = 0;
		for(i = 0; i < n; ++i){
			j = (i + 1) % n;
			area += x[i] * y[j];
			area -= y[i] * x[j];
		}
		printf("%.0lf\n", fabs(area) / 2.0);
	}
	return 0;
}

