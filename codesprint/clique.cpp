#include <cstdio>

int m, n;
int f(int r){
	int a = n % r;
	int b = r - a;
	int x = n / r;
	int y = x + 1;
	return (b*x*(n-x) + a*y*(n-y)) >> 1;
}

int main(void){
	int t; scanf("%d", &t);
	for(; t-- && scanf("%d %d", &n, &m) == 2; ){
		int mid, u, v;
		for(u = 0, v = n + 1; u < v; ){
			mid = (u + v) >> 1;
			if(f(mid) < m) u = mid + 1;
			else v = mid;
		}
		printf("%d\n", u);
	}
	return 0;
}

