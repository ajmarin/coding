#include <cmath>
#include <cstdio>

const double pi = acos(-1);
int main(void){
	for(int a, b, c; scanf("%d %d %d", &a, &b, &c) == 3; ){
		double s = (a + b + c) * .5;
		double area = sqrt(s * (s - a) * (s - b) * (s - c));
		double r = area / s, R = .25 * (a * b * c) / area;
		double outer = pi * R * R - area;
		double inner = pi * r * r;
		area -= inner;
		printf("%.4lf %.4lf %.4lf\n", outer, area, inner);
	}
	return 0;
}

