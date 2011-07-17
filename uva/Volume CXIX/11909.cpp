#include <cmath>
#include <cstdio>

const double conv = acos(-1)/180;
int main(void){

	for(int h, l, t, w; scanf("%d %d %d %d", &l, &w, &h, &t) == 4; ){
		double trad = t * conv, trih = l * tan(trad);
		if(trih > h) printf("%.3lf mL\n", .5*h*h*w/tan(trad));
		else printf("%.3lf mL\n", l*w*(h - .5*l*tan(t*conv)));
	}
	return 0;
}

