#include <cstdio>

typedef long long LL;
void r(int &t, int &n, int p){
	if(n % p) return;
	t /= p;
	t *= p - 1;
	while(!(n % p)) n /= p;
}

int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int t = n;
		r(t, n, 2);
		r(t, n, 3);
		for(int i = 6; ; i += 6){
			r(t, n, i - 1);
			r(t, n, i + 1);
			if((long long)i * i >= n) break;
		}
		if(n != 1) r(t, n, n);
		printf("%d\n", t >> 1);
	}
	return 0;
}

