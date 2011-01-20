#include <cmath>
#include <cstdio>
#include <ctime>
int ans = 0;
const int LRT = 1001, MAX = 1000001;
bool prime[MAX];
int pl[MAX >> 3], pc = 1;
void eratosthenes(){
	for(int i = 0; i < MAX; ++i) prime[i] = 1;
	prime[0] = prime[1] = 0; pl[pc++] = 2;
	for(int i = 4; i < MAX; i += 2) prime[i] = 0;
	for(int i = 3; i < LRT; i += 2)
		if(prime[i]){
			pl[pc++] = i;
			for(int j = i * i; j < MAX; j += i) prime[j] = 0;
		}
	for(int i = LRT + !(LRT & 1); i < MAX; i += 2)
		if(prime[i]) pl[pc++] = i;
}
int main(void){
	clock_t ini = clock();
	eratosthenes();	
	printf("Sieve took: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	for(int i = 7000; ; ++i){
		long long p = 2;
		if(i & 1) p = 2LL * pl[i] * i;
		if(p > 10000000000LL) { ans = i; break;} 
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
