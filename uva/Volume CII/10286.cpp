#include <cstdio>
#include <cmath>

const double pi = acos(-1);
const double cv = sin((108 * pi)/ 180) / sin((63 * pi)/180);

int main(void){
	double n;
	while(scanf("%lf",&n)==1) printf("%.10lf\n",n * cv);
	return 0;
}

