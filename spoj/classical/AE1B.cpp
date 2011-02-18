#include <algorithm>
#include <cstdio>
int x[1024];
int main(void){
	int k, n, s; scanf("%d %d %d", &n, &k, &s);
	int i, need = k * s;
	for(i = s = 0; i < n; ++i) scanf("%d", x + i), s += x[i];
	std::sort(x, x + n);
	for(i = 0; s - x[i] >= need; s -= x[i++]);
	printf("%d\n", n - i);
	return 0;
}

