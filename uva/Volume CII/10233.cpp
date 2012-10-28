#include <cmath>
#include <cstdio>

const double rt3 = sqrt(3), rt32 = rt3 / 2.0, rt36 = rt3 / 6.0;

double dist(double xa, double ya, double xb, double yb){
	return hypot(xa - xb, ya - yb);
}

int main(void){
	int la, lb, sla, slb;
	double xa, xb, ya, yb;
	for(int a, b; scanf("%d %d", &a, &b) == 2; ){
		if(a < b) a ^= b ^= a ^= b;
		la = int(sqrt(a)), lb = int(sqrt(b));
		sla = la * la, slb = lb * lb;
		xa = 0.5 * (a - sla);
		ya = ((a - sla) & 1) * rt36;
		xb = 0.5 * (la - lb + b - slb);
		yb = rt32 * (la - lb) + ((b - slb) & 1) * rt36;
		printf("%.3lf\n", dist(xa, ya, xb, yb));
	}
	return 0;
}

