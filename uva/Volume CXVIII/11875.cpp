#include <cstdio>
int v[128];
int main(void){
	int n, t; scanf("%d", &t);
	for(int c = 0; c < t; ++c){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) scanf("%d", &v[i]);
		printf("Case %d: %d\n", c + 1, v[n >> 1]);
	}
	return 0;
}

