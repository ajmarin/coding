#include <cmath>
#include <cstdio>
#include <ctime>
int w[512];
// Fills a row of n tiles with tiles of size >= m
int count(int m, int n){
	if(m > n) return 1;
	int r = 1 + w[n - 1]; // All reds (n > m), add a black to the left
	for(int x = m; x < n; ++x) r += w[n - x - 1]; // add a black then x reds
	return r;
}	
int build(int m){
	for(int i = 0; i < 512; ++i) w[i] = 0;
	for(int i = 0; ; ++i){
		w[i] = i < m ? 1 : count(m, i);
		if(w[i] > 1000000) return i;
	}
}
int main(void){
	clock_t ini = clock();
	int ans = build(50);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
