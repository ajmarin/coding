#include <cmath>
#include <cstdio>
#include <ctime>

long long x = 0;
long long fact(int x){ return x ? x * fact(x - 1) : 1; }
void bt(long long w, int b, int r){
	if(b + r == 15){
		x += w;
		return;
	}
	if(r < 7) bt(w * (b + r + 1), b, r + 1);
	bt(w, b + 1, r);
}
int main(void){
	clock_t ini = clock();
	bt(1, 0, 0);
	long long ans = fact(16) / x;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
