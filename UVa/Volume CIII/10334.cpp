#include <algorithm>
#include <cstdio>
#include <cstring>

#define HMF 1001
#define MAX(a,b) ((a)>(b)?(a):(b))

struct F { char fib[HMF>>1]; int n;} f[HMF], A, B;
int max; 
int main(void){
	int i, j, N;
	f[0].fib[0] = '1'; f[1].fib[0] = '2';
	f[0].fib[1] = f[1].fib[1] = 0;
	f[0].n = f[1].n = 1;
	for(i = 2; i < HMF; ++i){
		bool c = 0;
		int x = i - 2, y = x + 1, l1 = f[x].n, l2 = f[y].n;
		char *p = f[x].fib, *s = f[y].fib, *t = f[i].fib;
		for(j = l1; j < l2; ++j) f[x].fib[j] = '0';
		f[x].fib[l2] = 0;
		for( ; *p; ++t){
			*t = *p++ - '0' + *s++ - '0' + c;
			c = *t > 9; *t = *t % 10 + '0';
		}

		if(c) *t++ = '1';
		*t = f[x].fib[l1] = 0;
		f[i].n = t - f[i].fib;
	}
	for(i = 0; i < HMF; ++i) std::reverse(f[i].fib, f[i].fib + f[i].n);
	while(scanf("%d", &N) == 1)	puts(f[N].fib);
	return 0;
}

