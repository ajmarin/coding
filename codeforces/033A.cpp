#include <cstdio>

int t[1005], r[1005];
int main(void){
	int k, m, n, x, y; scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < 1005; ++i) r[i] = 0;
	while(n--){
		scanf("%d %d", &x, &y);
		if(!r[x]) t[x] = y;
		else if(y < t[x]) t[x] = y;
		r[x]++;
	}
	x = 0;
	for(int i = 1; i <= m; ++i) x += t[i];
	printf("%d\n", x > k ? k : x);
	return 0;
}

