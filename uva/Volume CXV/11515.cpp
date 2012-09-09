#include <algorithm>
#include <cstdio>
using namespace std;

int d[16][16], r[16], x[16], y[16];
int sqr(int x){ return x * x; } 
bool cranes_intersect(int a, int b){ return d[a][b] <= sqr(r[a] + r[b]); }

int area(int n, int mask){
	int ret = 0;
	for(int i = 0; i < n; ++i) if(mask & (1 << i)){
		ret += sqr(r[i]);
		for(int j = i + 1; j < n; ++j)
			if(mask & (1 << j) && cranes_intersect(i, j)) return 0;
	}
	return ret;
}
int main(void){
	int t; scanf("%d", &t);
	for(int n; scanf("%d", &n) == 1; ){
		for(int i = 0; i < n; ++i){
			scanf("%d %d %d", x + i, y + i, r + i);
			for(int j = 0; j < i; ++j) d[i][j] = d[j][i] = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
		}
		int max_area = 0;
		for(int i = 0; i < (1 << n); ++i) max_area = max(max_area, area(n, i));
		printf("%d\n", max_area);
	}
}

