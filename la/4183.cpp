#include <cstdio>
const int MAX = 100048;
int b[MAX]; // ARRAY DE INDICES DA LIS
int nums[MAX]; // ARRAY DE NUMEROS
int lis(int n){
	if (n < 1) return 1;
	int i, u, v, tail = -1;
	b[++tail] = 0;
	for (i = 1; i < n; i++) {
		if (nums[b[tail]] < nums[i]) {
			b[++tail] = i;
			continue;
		}
		for (u = 0, v = tail; u < v;) {
			int c = (u + v)>>1;
			if (nums[b[c]] < nums[i]) u=c+1; else v=c;
		}
		if (nums[i] < nums[b[u]]) {
			b[u] = i;
		}	
	}
	return tail + 1;
}
int main(void){
	for(int n; scanf("%d", &n) == 1 && n >= 0; ){
		for(int i = 0; i < n; ++i) scanf("%d", nums + i);
		printf("%d\n", lis(n));
	}
	return 0;
}

