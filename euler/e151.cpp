#include <cmath>
#include <cstdio>
#include <ctime>

const int BATCHES = 15; // Batch 15 is the last since we don't want the 16th
int box[4] = {1, 1, 1, 1}; // 1 of each size (A2, A3, A4, A5)
double ans = 0;
void bt(int b, int t, double p){
	if(b == BATCHES) return;
	ans += (t == 1) * p;
	for(int i = 0; i < 4; ++i) if(box[i]){
		for(int j = 0; j < 4; ++j) box[j] += (j > i) - (i == j);
		bt(b + 1, t + 2 - i, p * (box[i]+1) / t);
		for(int j = 0; j < 4; ++j) box[j] += (i == j) - (j > i);
	}
}
int main(void){
	clock_t ini = clock();
	bt(1, 4, 1.0);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %.6lf\n", ans);
	return 0;
}
