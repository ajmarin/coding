#include <cstdio>

int main(void){
	int a, b, c, d, e, f;
	int den, n1, n2;
	double x, y;
	while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f)){
		if(!(a || b || c || d || e || f)) break;
		den = a * e - b * d;
		if(den){
			n1 = c * e - b * f;
			n2 = a * f - c * d;
			if(n1) x = n1 / (double) den;
			else x = 0.0;
			if(n2) y = n2 / (double) den;
			else y = 0.0;
			printf("The fixed point is at %.2lf %.2lf.\n", x, y);
		} else printf("No fixed point exists.\n");
	}
	return 0;
}

