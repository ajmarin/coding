#include <cstdio>
#include <ctime>

const int LIM = 1000000;
int cnt[LIM];
int main(void){
	clock_t start = clock();
	int ans = 0;
	for(int i = 0; i < LIM; ++i) cnt[i] = 0;
	// (x + a)^2 - x^2 - (x - a)^2 = n  obviously x > a
	// 4xa - x^2 = n
	// a = (n + x^2) / 4x ==> n = k x
	// a = (k + x) / 4
	// b is such that (b + x) % 4 = 0
	// k = 4y + b
	// a = (b + 4y + x) / 4
	// since a < x
	// (b + 4y + x) < 4x ==> y < (3x - b) / 4 ==> LY
	// n = (b + 4y) * x < 1000000
	for(int b, n, x = 2; x < LIM; ++x){
		int LY = (3 * x - ( b = 4 - (x % 4) ) ) >> 2;
		for(int y = 0; y < LY; ++y){	
			n = x * (b + 4 * y);
			if(n >= LIM) break;
			ans += ++cnt[n] == 10;
			ans -= cnt[n] == 11;
		}
	}
	printf("Answer: %d\n", ans);
	printf("Time spent: %.3lfs\n", (clock() - start) / double(CLOCKS_PER_SEC));
	return 0;
}

