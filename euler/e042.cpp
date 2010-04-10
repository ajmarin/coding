#include <cmath>
#include <cstdio>
#include <ctime>

char word[64];
int main(void){
	clock_t ini = clock();
	int ans = 0, value;
	while(scanf("%s", word) == 1){
		char *p = word;
		value = 0;
		while(*p) value += *p++ - 'A' + 1;
		int test = (value << 3) + 1, root = (int)sqrt(test);
		ans += root * root == test;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

