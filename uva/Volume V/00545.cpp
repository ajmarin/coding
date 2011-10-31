#include <cmath>
#include <cstdio>
#include <cstdlib>

double log10_2 = log10(2);
int main(void){
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1; ){
		int x = floor(-n * log10_2);
		double k = pow(10, -n*log10_2 - x);
		printf("2^-%d = %.3lfE%d\n", n, k, x);
	}
	return 0;
}

