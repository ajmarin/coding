#include <cmath>
#include <cstdio>
#include <ctime>
const int MAX = 1000001;
int cnt[MAX];
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < MAX; ++i) cnt[i] = 0;	
	for(long long i = 1; i < 500000; ++i)
		for(long long j = i + 2; ; j += 2){
			long long d = j * j - i * i;
			if(d > 1000000) break;
			++cnt[d];
		}
	for(int i = 0; i < MAX; ++i)
		ans += cnt[i] && cnt[i] < 11;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
