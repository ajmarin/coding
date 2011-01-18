#include <cmath>
#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int ans = -1; double maxv = -1;
	freopen("base_exp.txt", "r", stdin);
	for(int b, e, line = 1; scanf("%d,%d", &b, &e) == 2; ++line){
		if(e * log(b) > maxv){
			maxv = e * log(b);
			ans = line;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
