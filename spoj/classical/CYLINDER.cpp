#include <cstdio>
#define PI 3.1415926535897931159979635
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(void){
	int a, b;
	double h1, h2, r1, r2, v1, v2;
	while(scanf("%d%d",&a,&b) && a){
		r1 = a/(2.0*PI);
		h1 = b - 2*r1;
		r2 = MIN(b/(2.0*(PI+1.0)),a/2.0);
		h2 = a;
		v1 = (PI*r1*r1*h1);
		v2 = (PI*r2*r2*h2);
		//printf("r1(%.5lf) h1(%.5lf) v1(%.5lf)\n",r1,h1,v1);
		//printf("r2(%.5lf) h2(%.5lf) v2(%.5lf)\n",r2,h2,v2);
		if(v1 > v2) printf("%.3lf\n",v1);
		else printf("%.3lf\n",v2);

	}
	return 0;
}
		
