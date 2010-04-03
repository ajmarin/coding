#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 10000
#define PMAX 1500
#define MSQRT 100

bool p[MAX];
int memd[MAX], f[15], pl[PMAX];
int ans = 0, c = 1, fn;

int factor_sum(int n, int idx){
	int l = -1, r = n;
	for(int i = idx; i < fn; ++i)
		if(f[i] != l) r += factor_sum(n * f[i], i + 1), l = f[i];
	return r;
}
void factor(int k){
	fn = 0;
	for(int i = 0; k != 1; ++i){
		int x = pl[i];
		if(!(k % x)) do { k /= x; f[fn++] = x; } while(!(k % x));
	}
}
int d(int k){
	if(memd[k]) return memd[k];
	factor(k);
	return memd[k] = factor_sum(1, 0) - k;
}
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < MAX; ++i) p[i] = 1, memd[i] = 0;
	pl[0] = 2;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < MSQRT; i += 2)
		if(p[i]){
			pl[c++] = i;
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	for(int i = MSQRT + !(MSQRT & 1); i < MAX; i += 2)
		if(p[i]) pl[c++] = i;
	for(int i = 2; i < 10000; ++i){
		int x = d(i);
		if(x < 10000 && x != i && d(x) == i) ans += i;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

