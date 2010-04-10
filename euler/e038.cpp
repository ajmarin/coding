#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

char cd[11], num[6];
int ans = 0;
void test(int k){
	strcpy(cd, "0000000000");
	int c = 0, concat_num = 0;
	for(int i = 1; i < 10; ++i){
		int x = k * i, p = 0;
		while(x){
			if(++cd[x % 10] > '1') return;
			num[p++] = x % 10;
			x /= 10;
		}
		while(p--) concat_num = concat_num * 10 + num[p];
		if(strcmp(cd, "0111111111") == 0) break;
	}
	if(concat_num > ans) ans = concat_num;
}
int main(void){
	clock_t ini = clock();
	for(int i = 1; i < 10000; ++i) test(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

