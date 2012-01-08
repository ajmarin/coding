#include <cstdio>
#include <cstring>
#include <ctime>

const int DIGITS = 21;
long long ans[10][10][20];

long long count(int d0, int d1, int r){
	if(r == 0) return 1;
	if(ans[d0][d1][r] != -1) return ans[d0][d1][r];
	long long &ret = ans[d0][d1][r] = 0;
	for(int i = r == 20; i < 10 - (d0 + d1); ++i) ret += count(d1, i, r - 1);
	return ret;
}

int main(void){
	clock_t start = clock();
	memset(ans, 0xFF, sizeof ans);
	printf("Answer: %lld\n", count(0, 0, DIGITS - 1));
	printf("Time spent: %.3lfs\n", (clock() - start) / double(CLOCKS_PER_SEC));
	return 0;
}

