#include <algorithm>
#include <cstdio>
using namespace std;

int d[1048576];
int sqr[30001];
int x[1024], y[1024];

int main(void){
	int t; scanf("%d", &t);
	for(int i = 0; i < 30001; ++i) sqr[i] = i * i;
	for(int c = 0, n; c++ < t && scanf("%d", &n) == 1; ){
		int z = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %d", x + i, y + i);
			for(int j = 0; j < i; ++j)
				d[z++] = sqr[abs(x[i] - x[j])] + sqr[abs(y[i] - y[j])];
		}
		d[z] = -1;
		sort(d, d + z);
		int ans = 1;
		for(int i = 1; i <= z; ++i) ans += d[i] != d[i - 1];
		printf("Case %d: %d\n", c, ans);
	}
	return 0;
}

