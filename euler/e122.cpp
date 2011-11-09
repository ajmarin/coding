#include <cstdio>
#include <ctime>

int cost[256], p[256];

int min(int a, int b){ return a < b ? a : b; }
void bt(int power, int depth){
	if(power > 200 || depth > cost[power]) return;
	cost[power] = depth;
	p[depth] = power;
	for(int i = depth; i >= 0; --i)
		bt(power + p[i], depth + 1);
}
int main(void){
	int ans = 0;
	clock_t start = clock();
	for(int i = 0; i < 256; ++i) cost[i] = 1024;
	bt(1, 0);
	for(int i = 1; i <= 200; ++i) ans += cost[i];
	printf("Answer: %d\n", ans);
	printf("Elapsed time: %.6lfs\n", (clock() - start) / double(CLOCKS_PER_SEC));

	return 0;
}
