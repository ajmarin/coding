#include <algorithm>
#include <cstdio>
#include <cstring>

#define HMF 500
#define MAX(a,b) ((a)>(b)?(a):(b))

struct F {
	char fib[128], n;
	bool operator<(const F x) const {
		return n < x.n || (n == x.n && strcmp(fib,x.fib) < 0);
	}
} f[512], A, B;
int max; 
int find(F x){
	int u, v;
	for(u = 0, v = max; u < v; ){
		int c = (u + v) >> 1;
		if(f[c] < x) u = c + 1; else v = c;
	}
	return u;
}
int main(void){
	int i, j;
	f[0].fib[0] = '1'; f[1].fib[0] = '2';
	f[0].fib[1] = f[1].fib[1] = 0;
	f[0].n = f[1].n = 1;
	for(i = 2; i < 512; ++i){
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
		if(f[i].n > 103){ max = i++; break; }
	}
	for(i = 0; i <= max; ++i) std::reverse(f[i].fib, f[i].fib + f[i].n);
	while(scanf("%s %s", A.fib, B.fib)){
		if(A.fib[0] == B.fib[0] && A.fib[0] == '0') break;
		A.n = strlen(A.fib); B.n = strlen(B.fib);
		int a = find(A), b = find(B);
		if(strcmp(f[b].fib, B.fib)) b--;
		printf("%d\n",MAX(b - a + 1, 0));
	}
	return 0;
}

