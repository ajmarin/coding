#include <cmath>
#include <cstdio>
#include <ctime>

bool prime(int x){
	if(x == 2 || x == 3 || x == 5 || x == 7) return true;
	if(!(x & 1) || !(x % 3)) return false;
	for(int i = 6; ; i += 6){
		int t1 = i - 1, t2 = i + 1;
		if(!(x % t1) || !(x % t2)) return false;
		if(t2 * t2 > x) return true;
	}
}
int main(void){
	clock_t ini = clock();
	long long ans = -1;
	const int X = 2000;
	for(int c = 2, r = 2; ; ++r){
		int rs = 6 * r;
		if(prime(rs - 1)){
			if(prime(rs + 1) && prime(2 * rs + 5) && ++c == X)
				ans = 3LL * r * (r - 1) + 2;
			if(prime(rs + 5) && prime(2 * rs - 7) && ++c == X) 
				ans = 3LL * r * (r + 1) + 1;
		}
		if(c >= X) break;
	}	
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
