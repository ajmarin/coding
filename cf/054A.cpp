#include <cstdio>

int v[512];
int main(void){
	int c, k, n; scanf("%d %d %d", &n, &k, &c);
	int idx = 0, lp = 0, pc = 0;
	for(int i = 0; i < c; ++i)
		scanf("%d", &v[i]);
	for(int i = 1; i <= n; ++i)
		if(i - lp == k || v[idx] == i){
			idx += v[idx] == i;
			lp = i;
			++pc;
		}
	printf("%d\n", pc);
	return 0;
}