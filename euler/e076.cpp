#include <cstdio>
#include <ctime>

int ans = 0;
void r(int s, int m){
	if(s == 100){
		ans++;
		return;
	}
	int lim = 101 - s;
	for(int i = m; i < lim; ++i) r(s + i, i);
}
int main(void){
	clock_t ini = clock();
	for(int i = 1; i < 51; ++i) r(i, i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
