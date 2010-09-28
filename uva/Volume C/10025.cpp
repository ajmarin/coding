#include <cstdio>
#include <cmath>

int main(void){
	int k, n, t, v;
	for(scanf("%d", &t); t-- && scanf("%d", &k) == 1; ){
		if(k == 0) puts("3");
		else {
			if(k < 0) k = -k;
			v = ceil(sqrt(1 + k * 8LL));
			v += !(v & 1);
			n = (-1 + v) >> 1;
			if((((n + 1) >> 1) & 1) != (k & 1)) n = n + 1 + (n & 1);
			printf("%d\n", n);
		}
		if(t) putc(10, stdout);
	}
	return 0;
}

