#include <cstdio>

int main(void){
	for(int n, m, c; scanf("%d %d %d", &n, &m, &c) == 3 && n; ){
		int even = (m - 7 + c) >> 1, odd = m - 7 - even;
		printf("%d\n", even * ((n - 6) / 2) + odd * ((n - 7) / 2));
	}
	return 0;
}

