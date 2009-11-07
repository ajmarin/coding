#include <cstdio>
#include <cmath>

const double EPS = 1e-5;

bool red = 0;
int main(void){
	int k, m, n;
	double a1, a2, a3, move;
	while(scanf("%d%d",&n,&m) == 2){
		a1 = 10000/(double)(n + m);
		a2 = 10000/(double)(n);
		a3 = move = 0;
		for(int i = 0; i < n; ++i){
			a3 += a2;
			k = floor(a3 / a1);
			a3 -= k * a1;
			double sp1 = a1 - a3;
			if(a3 < sp1) sp1 = a3;
			move += sp1;
		}
		printf("%.4lf\n", move);
	}

	return 0;
}
