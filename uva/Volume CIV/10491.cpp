#include <cstdio>

int main(void){
	int NC, NW, NS;
	while(scanf("%d %d %d", &NW, &NC, &NS) == 3){
		int T = NW + NC;
		printf("%.5lf\n", (NC * (T - 1)/(double)(T * (T - NS - 1))));
	}
	return 0;
}

