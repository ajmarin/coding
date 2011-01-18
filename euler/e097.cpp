#include <cmath>
#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	long long ans = 1;
	int power = 7830457;
	while(power > 26){
		ans = (ans << 27) % 10000000000LL;
		power -= 27;
	}
	ans = (ans << power) % 10000000000LL;
	ans = (28433 * ans + 1) % 10000000000LL;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
