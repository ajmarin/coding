#include <cmath>
#include <cstdio>
#include <ctime>
const int MAX = 1000000, MAXS = 2177281;
int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int cs[MAXS], q[MAXS];
int fdsum(int n){
	for(int r = 0; ; ){
		r += f[n % 10], n /= 10;
		if(!n) return r;
	}
	return 0;
}
int chain(int n){
	int c = 0, qs = 0;
	while(!cs[n]){
		bool out = 0;
		for(int i = 0; i < qs; ++i) out |= q[i] == n;
		if(out) break;
		q[qs++] = n;
		n = fdsum(n);
	}
	c = qs + cs[n];
	for(int i = 0; i < qs; ++i){
		cs[q[i]] = c--;
		if(q[i] == n) break;
	}
	return cs[q[0]];
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < MAXS; ++i) cs[i] = 0;
	for(int i = 0; i < MAX; ++i) ans += chain(i) == 60;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

