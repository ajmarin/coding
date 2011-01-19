#include <cmath>
#include <cstdio>
#include <ctime>
const long long p9 = 1000000000LL, p15 = 1000000000000000LL;
bool pandigital(int x){
	int p = 1, s = 0;
	while(x) p *= x % 10, s += x % 10, x /= 10;
	return p == 362880 && s == 45;
}
int main(void){
	clock_t ini = clock();
	long long f, f1 = 1, f2 = 0, l, l1 = 1, l2 = 0, x;
	int ans = 0;
	for(int i = 2; ; ++i){
		f = f1 + f2; f2 = f1; f1 = f;
		l = (l1 + l2) % p9; l2 = l1; l1 = l;
		while(f > p15){
			f /= 10;
			f1 /= 10;
			f2 /= 10;
		}
		if(pandigital(l)){
			for(x = f; x > p9; x /= 10);
			if(pandigital(x)){
				printf("F[%d] = %lld...%lld\n", ans = i, x, l);
				break;
			}
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;	
}
