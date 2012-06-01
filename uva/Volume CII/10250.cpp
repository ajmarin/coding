#include <cstdio>

int main(void){
	long double x1, x2, xm, y1, y2, ym;
	while(scanf("%Lf %Lf %Lf %Lf", &x1, &y1, &x2, &y2) == 4){
		xm = (x1 + x2) * .5;
		ym = (y1 + y2) * .5;
		printf("%Lf %Lf %Lf %Lf\n", xm - ym + y1, ym + xm - x1, xm + ym - y1, ym - xm + x1);
	}
	return 0;
}

