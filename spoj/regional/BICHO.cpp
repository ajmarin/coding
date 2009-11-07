#include <cstdio>
int main(void){
	int i, m, n, v1, v2;
	double v;
	while(scanf("%lf%d%d",&v,&n,&m) && v){
		int mult = 0;
		if(n%10000 == m%10000) mult = 3000;
		else if(n%1000 == m%1000) mult = 500;
		else if(n%100 == m%100) mult = 50;
		else {
			v1 = n%100; v2 = m%100;
			if(!v1) v1 = 100;
			if(!v2) v2 = 100;
			if((v1-1)>>2 == (v2-1)>>2) mult = 16;
		}
		printf("%.2lf\n",v*mult);
	}
	return 0;
}
