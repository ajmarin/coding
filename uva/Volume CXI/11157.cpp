#include <cstdio>

int v[256];
char type[8];

int max(int a, int b){ return a > b ? a : b; }
int main(void){
	int t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		int ans = 0, d, i, j, n, z;
		scanf("%d %d", &n, &d);
		v[0] = v[1] = 0;
		for(i = 0, j = 2; i < n; ++i){
			scanf("%1s-%d", type, &z);
			v[j++] = z;
			if(type[0] == 'B') v[j++] = z;
		}
		v[j++] = d;
		v[j++] = d;
		for(i = 2; i < j; ++i) ans = max(ans, v[i] - v[i - 2]);
		printf("Case %d: %d\n", c, ans);
	}
	return 0;
}

