#include <cmath>
#include <cstdio>

int main(void){
	int d, g, l, r, ttl, v;
	double eta;
	scanf("%d %d %d %d %d", &l, &d, &v, &g, &r);
	eta = l /(double) v;
	ttl = d % ((g + r) * v);
	if(ttl >= g * v)  eta += ((r + g) * v - ttl)/(double)v;
	printf("%.8lf\n", eta);
	return 0;
}

