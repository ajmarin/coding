#include <cstdio>
int main(void){
	float a, g, ra, rg;
	scanf("%f%f%f%f",&a,&g,&ra,&rg);
	if((ra/a) > (rg/g)) puts("A");
	else puts("G");
	return 0;
}
