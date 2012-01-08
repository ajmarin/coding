#include <cstdio>
#include <cstring>
#include <ctime>


int MAX_D;
long long ans[2][2][2][17];

long long count(bool has0, bool has1, bool hasA, int r){
	if(r == 0) return has0 && has1 && hasA;
	long long &ret = ans[has0][has1][hasA][r];
	if(ret != -1) return ret;
	ret = 0;
	for(int i = r == MAX_D; i < 16; ++i)
		ret += count(has0 | (i == 0), has1 | (i == 1), hasA | (i == 10), r - 1);
	return ret;
}


int main(void){
	clock_t start = clock();
	long long answer = 0;
	for(int i = 3; i <= 16; ++i){
		memset(ans, 0xFF, sizeof ans);
		answer += count(false, false, false, MAX_D = i);
	}
	printf("Answer: %llX\n", answer);
	printf("Time spent: %.3lfs\n", (clock() - start) / double(CLOCKS_PER_SEC));
	return 0;
}

