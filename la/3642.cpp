#include <cstdio>

const int MAXN = 400001;
int best[MAXN];
int sqsum[1000];
int cube[1000];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int i = 0; ; ++i) if((sqsum[i] = (i*(2*i+1)*(i+1)) / 6) > MAXN) break;
	for(int i = 0; ; ++i) if((cube[i] = i*i*i) > MAXN) break;
	for(int i = 0; i < MAXN; ++i) best[i] = 1 << 30;
	best[0] = 0;
	for(int i = 1; i < MAXN; ++i){
		for(int j = 1; sqsum[j] <= i; ++j)
			best[i] = min(best[i], best[i - sqsum[j]] + 1);
		for(int j = 1; cube[j] <= i; ++j)
			best[i] = min(best[i], best[i - cube[j]] + 1);
	}
	for(int n; scanf("%d", &n) == 1 && n != -1; printf("%d\n", best[n]));
	return 0;
}

