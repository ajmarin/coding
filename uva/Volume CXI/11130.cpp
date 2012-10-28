#include <cmath>
#include <cstdio>

const double conv = acos(-1) / 180;
int bnc(int z, int v, int A, int s, double (*func)(double)){
	return int((z + v * func(A * conv) * s) / (z << 1));
}
int main(void){
	for(int a, b, v, A, s; scanf("%d %d %d %d %d", &a, &b, &v, &A, &s) == 5; ){
		if(!(a | b | v | A | s)) break;
		printf("%d %d\n", bnc(a, v, A, s, cos), bnc(b, v, A, s, sin));
	}
	return 0;
}

