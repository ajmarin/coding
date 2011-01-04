#include <cmath>
#include <cstdio>
#include <ctime>
const int MAX = 1000001;
int phi[MAX];
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	for(int i = 2; i < MAX; ++i) phi[i] = i >> (!(i & 1));
	for(int i = 3; i < MAX; i += 2){
		if(phi[i] == i){
			for(int j = i; j < MAX; j += i){
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
		ans += phi[i] + phi[i - 1];
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

