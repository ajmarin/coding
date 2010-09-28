#include <cmath>
#include <cstdio>

const double pi = 2 * acos(0);
const double conv = pi/(double)180;
int main(void){
	int a, s;
	double angr, x1, x2, y1, y2;
	char t[8];
	while(scanf("%d %d %s", &s, &a, t) == 3){
		angr = a * conv;
		s = s + 6440;
		if(t[0] == 'm') angr /= 60.000000000;
		if(angr > pi) angr = 2 * pi - angr;
		x1 = s; y1 = 0;
		x2 = s * cos(angr); y2 = s * sin(angr);
		printf("%.6lf %.6lf\n", angr * s, hypot(x2 - x1, y2 - y1));
	}
	return 0;
}
		
