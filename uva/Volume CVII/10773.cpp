#include <cmath>
#include <cstdio>

int main(void){
	int cases;
	scanf("%d", &cases);
	for(int c = 0, d, v, u; c++ < cases && scanf("%d %d %d", &d, &v, &u) == 3; ){
		printf("Case %d: ", c);
		if(v < u && u && v) printf("%.3lf\n", d / sqrt(u*u - v*v) - d / double(u));
		else puts("can\'t determine");
	}
	return 0;
}

