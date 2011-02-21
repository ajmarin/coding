#include <cmath>
#include <cstdio>
const double c = .5/acos(-1);
int main(void){
	for(int L; scanf("%d", &L) == 1 && L; )
		printf("%.2lf\n", L * L * c);
	return 0;
}

