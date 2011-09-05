#include <cmath>
#include <cstdio>
const double pi = acos(-1);
const double conv = acos(-1) / 180;

int main(void){
	int rig = 1;
	for(int r; scanf("%d", &r) == 1 && r; ){
		if(rig > 1) puts("");
		printf("Test Rig %d\n", rig++);
		for(int D, alfa; scanf("%d %d", &D, &alfa) == 2 && (D || alfa); ){
			if(alfa > 90) alfa = 180 - alfa;
			if(alfa == 90){
				printf("%d\n", D / (2 * r));
			} else {
				double beta = (90 - alfa) * conv;
				double d = r * sin(pi - 2 * beta) / sin(beta);
				printf("%d\n", int(D / d));
			}
		}
	}
	return 0;
}

