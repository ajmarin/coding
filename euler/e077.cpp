#include <cstdio>
#include <ctime>

int p[25] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
			 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
int ans = 1, ways = 0;
void r(int s, int m){
	if(s >= ans){
		ways += (s == ans);
		return;
	}
	for(int i = m; i < 25; ++i) r(s + p[i], i);
}
int main(void){
	clock_t ini = clock();
	while(ways < 5001){
		ways = 0; ++ans;
		for(int i = 0; i < 25; ++i) r(p[i], i);
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
