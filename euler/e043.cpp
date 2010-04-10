
#include <cmath>
#include <cstdio>
#include <ctime>

long long ans = 0;
int d[10], div[7] = { 2, 3, 5, 7, 11, 13, 17 };
bool used[10];
void b(int u, long long n){
	if(u > 3){
		int k = d[u - 3] * 100 + d[u - 2] * 10 + d[u - 1];
		if(k % div[u - 4]) return;
		if(u == 10){ ans += n; return; }
	}
	for(int i = 10; i--; ){
		if(!used[i]){
			if(!i && !u) continue;
			used[i] = 1;
			d[u] = i;
			b(u + 1, n * 10 + i);
			used[i] = 0;
		}
	}
}
int main(void){
	clock_t ini = clock();
	b(0, 0);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

