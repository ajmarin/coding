#include <cstdio>
#include <ctime>

const int MAXP = 100000005, ROOT = 10005;
bool prime[MAXP];

int main(void){
	long long ans = 1;
	clock_t start = clock();
	for(int i = 0; i < MAXP; ++i) prime[i] = i & 1;
	prime[1] = false;
	prime[2] = true;
	for(int i = 3; i < ROOT; i += 2) if(prime[i])
		for(int j = i * i, k = i << 1; j < MAXP; j += k)
			prime[j] = false;
	for(int i = 2; i < MAXP; i += 4) if(prime[i + 1]){ 
		ans += i;
		for(int j = 2; j * j <= i; ++j)
			if(!( i % j || prime[j + i / j])){
				ans -= i;
				break;
			}
	}
	printf("Answer: %lld\n", ans);
	printf("Elapsed time: %.3lfs\n", (clock() - start) / double(CLOCKS_PER_SEC));
	return 0;
}

