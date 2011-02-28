#include <cstdio>

typedef unsigned uint;
uint a[1024];
uint gcd(uint a, uint b){ return b ? gcd(b, a % b) : a; }
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		bool valid = true;
		uint g;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			uint x, v = 0;
			for(int j = 0; j < 9; ++j){ scanf("%u", &x); v += x; }
			scanf("%u", a + i);
			valid &= v >= a[i];
			v -= a[i];
			if(i) g = gcd(g, v);
			else g = v;
		}
		valid &= g > 1;
		for(int i = 0; i < n; ++i) valid &= a[i] < g;
		if(valid) printf("%u\n", g);
		else puts("impossible");
	}
	return 0;
}

