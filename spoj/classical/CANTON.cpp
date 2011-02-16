#include <cmath>
#include <cstdio>
int main(void){
	int n, t; scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int top = int(ceil(-.5 + sqrt(1 + (n << 3))/2.));
		int u = (top * (top + 1)) >> 1;
		if(top & 1) printf("TERM %d IS %d/%d\n", n, 1 + u - n, n - u + top);
		else printf("TERM %d IS %d/%d\n", n, n - u + top, 1 + u - n);
	}
	return 0;
}
