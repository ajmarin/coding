#include <cmath>
#include <cstdio>
#include <ctime>
typedef unsigned long long LL;
LL reverse(LL x){
	LL r;
	for(r = 0; x; r = r * 10 + x % 10, x /= 10);
	return r;
}
bool lychrel(LL x){
	bool p = 0;
	for(int i = 0; !p && i < 50; ++i){
		LL z = reverse(x);
		if(i && z == x) return 0;
		x += z;
	}
	return 1;
}
int main(void){
	int ans = 0;
	clock_t ini = clock();
	for(int i = 1; i < 10000; ++i) ans += lychrel(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

