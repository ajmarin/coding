#include <cstdio>
#include <ctime>

const int MAX = 20000001, ROOT = 4473;
bool p[MAX];
int pl[MAX/10], pc = 1;
int fs[MAX];

void go(int v, int idx, int sum){
	int lim = MAX / v;
	fs[v] = sum;
	for(int i = idx; i < pc && pl[i] <= lim; ++i)
		go(v * pl[i], i, sum + pl[i]);
}

int main(void){
	clock_t begin = clock();
	long long ans = 0;
	/* Sieve {{{ */
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < ROOT; i += 2)
		if(p[i]) for(int j = i*i, k = 2*i; j < MAX; j += k) p[j] = 0;
	pl[0] = 2;
	for(int i = 3; i < MAX; i += 2)
		if(p[i]) pl[pc++] = i;
	/* }}} */
	go(1, 0, 0);
	for(int i = 20000000; i > 15000000; --i)
		ans += fs[i];
	for(int i = 5000000; i > 1; --i)
		ans -= fs[i];
	printf("Answer: %lld\n", ans);
	printf("Time spent: %.3lfs\n", (double) (clock() - begin) / CLOCKS_PER_SEC);
	return 0;
}

