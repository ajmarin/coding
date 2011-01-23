#include <cmath>
#include <cstdio>
#include <ctime>

int PP[64], PC[64];
void dice(int s, int a, int sum, int *P){
	if(!a){ P[sum]++; return; }
	for(int i = 1; i <= s; ++i)	dice(s, a - 1, sum + i, P);
}
int main(void){
	clock_t ini = clock();
	long long ans = 0, pc_sum;
	for(int i = 0; i < 64; ++i) PC[i] = PP[i] = 0;
	dice(6, 6, 0, PC);
	dice(4, 9, 0, PP);
	pc_sum = PC[6] + PC[7] + PC[8];
	for(int i = 9; i < 37; ++i){
		printf("%lld %d\n", pc_sum, PP[i]);
		ans += pc_sum * PP[i];
		pc_sum += PC[i];
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %.7lf\n", ans / ((1<<24) * pow(3,6)));
	return 0;
}
