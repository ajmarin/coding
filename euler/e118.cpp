#include <cmath>
#include <cstdio>
#include <ctime>
int ans = 0;
const int LRT = 1001, MAX = 1000001;
bool prime[MAX];
int pl[MAX >> 3], pc = 0;
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
bool is_prime(int x){
	if(x < MAX) return prime[x];
	int i, lim = int(floor(sqrt(x))) + 1;
	for(int *k = pl; *k < lim; k++)
		if(!(x % *k)) return false;
	return true;
}
void bt(int n, int mask, int p){
	if(n > p && is_prime(n)){
		if(mask != 0x3FE) bt(0, mask, n);
		else { ++ans; return; }
	}
	for(int i = 1; i < 10; ++i)
		if(!(mask & (1 << i))) bt(n * 10 + i, mask | (1 << i), p);
}
int main(void){
	clock_t ini = clock();
	eratosthenes();
	printf("Sieve took: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	bt(0, 0, 0);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
