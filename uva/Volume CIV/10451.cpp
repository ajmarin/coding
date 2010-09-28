#include <cmath>
#include <cstdio>

const double PI = 2 * acos(0);
const double PI2 = 2 * PI;
int main(void){
	int n;
	double A;
	for(int c = 1; (scanf("%d %lf", &n, &A) && n > 2); ++c){
		double R = (A * 2.) / (n * sin(PI2 / n));
		double r = A / (n * tan(PI / n));
		printf("Case %d: %.5lf %.5lf\n", c, PI * R - A, A - PI * r);
	}
	return 0;
}

