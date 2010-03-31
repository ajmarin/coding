#include <cmath>
#include <cstdio>
#include <ctime>

#define DBG
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
bool go(int i){
	int r = floor(sqrt(i));
	if(r * r == i) return 0;
	int d = -r, g, n = 1, t;
	bool add = 0;
#ifdef DBG
	printf("sqrt(%d) = [ %d; (", i, r);
#endif
	while(1){
		add ^= 1;
		t = -d;
		d = i - d * d;
		g = gcd(n, d);
		n = d = d/g;
		if(d == 1) break;
#ifdef DBG
		printf("%d, ", (r + t) / d);
#endif
		d = t - ((r + t) / d) * d;
	}
#ifdef DBG
	printf("%d) ]\n", 2 * r);
#endif
	return add;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 2; i < 10001; ++i) ans += go(i);		
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
