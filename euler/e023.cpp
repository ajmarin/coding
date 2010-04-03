#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 40000
#define PMAX 4500
#define MSQRT 200
#define LIM 28124

bool p[MAX], is_ab[MAX];
int ab[MAX], pl[PMAX];
int abn = 0, ans = 0, c = 1;

int d(int k){
	int a = k, r = 1;
	for(int i = 0; ; ++i){
		int x = pl[i], v = 1;
		if(x * x > k) break;
		while(!(k % x)){
			v = v * x + 1;
			k /= x;
		}
		r *= v;
	}
	if(k > 1) r *= (1 + k);
	return r - a;
}
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < MAX; ++i) p[i] = 1, is_ab[i] = 0;
	pl[0] = 2;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < MSQRT; i += 2)
		if(p[i]){
			pl[c++] = i;
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	for(int i = MSQRT + !(MSQRT & 1); i < MAX; i += 2)
		if(p[i]) pl[c++] = i;
	for(int i = 2; i < LIM; ++i) if(d(i) > i) ab[abn++] = i, is_ab[i] = 1;
	for(int i = 1, j; i < 28124; ++i){
		int half = (i >> 1) + 1;
		for(j = 0; ab[j] < half; ++j)
			if(is_ab[ i - ab[j] ]) break;
		if(ab[j] >= half) ans += i;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

