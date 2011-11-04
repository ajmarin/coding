#include <cmath>
#include <cstdio>

const double conv = 180 / acos(-1);
double hyp(double a, double b){ return sqrt( a * a + b * b ); }
double deg(double rad){ return rad * conv; }
int main(void){
	for(int a, b, s, m, n; scanf("%d%d%d%d%d", &a, &b, &s, &m, &n) == 5; ){
		if(!(a + b + s + m + n)) break;
		printf("%.2lf %.2lf\n", deg(atan( n * b / double(m * a))), hyp(m * a, n * b) / s);
	}
	return 0;
}

