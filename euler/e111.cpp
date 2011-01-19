#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
typedef unsigned long long int LLU;
LLU sum;
bool prime(LLU x){
	if(x <= 1) return 0;
	if(x == 2 || x == 3 || x == 5 || x == 7) return 1;
	if(!(x & 1) || !(x % 3)) return 0;
	for(int z = 6; ; z += 6){
		LLU t1 = z - 1, t2 = z + 1;
		if(!(x % t1) || !(x % t2)) return 0;
		if(t2 * t2 > x) return 1;
	}
}
void doit(LLU n, int d, int r, int m){
	/*
	** n = the number itself
	** d = the digit we're repeating
	** r = how many times 'd' still needs to be used
	** m = how many digits are missing
	*/
	if(r < 0 || r > m) return;
	if(m == 0){ // our number is ready
		if(prime(n)) sum += n;
		return;
	}
	for(int i = m == 10; i < 10; ++i) // (m == 10) -> first digit can't be 0 
		doit(n * 10 + i, d, r - (i == d), m - 1);
}
int main(void){
	clock_t ini = clock();
	LLU ans = 0;
	for(int d = 0; d < 10; ++d) // for each digit
		for(int r = 9; r > -1; --r){ // looking for M(10, d) = r
			sum = 0; // sum for 10 digit primes with d appearing r times
			doit(0, d, r, 10);
			if(sum){
				ans += sum;
				break;
			}
		}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
