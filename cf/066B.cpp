#include <cstdio>
int h[1024];
int main(void){
	int maxw = 0, n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", h + i);
	for(int i = 0; i < n; ++i){
		int l, r;
		for(l = i; l > 0 && h[l - 1] <= h[l]; --l);
		for(r = i; r < n-1 && h[r + 1] <= h[r]; ++r);
		if(r - l + 1 > maxw) maxw = r - l + 1;
	}
	printf("%d\n", maxw);
	return 0;
}

