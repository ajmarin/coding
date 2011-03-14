#include <cstdio>
typedef long long LL;
LL f(LL t, LL c, LL n){
	return t * (c - t * n);
}
int main(void){
	for(int c, n; scanf("%d %d", &n, &c) == 2; ){
		LL t;
		if(n) {
			t = (c / (2 * n));
			while(f(t + 1, c, n) > f(t, c, n)) t++;
		}
		printf("%d\n", n ? int(t) : 0);
	}
	return 0;
}

