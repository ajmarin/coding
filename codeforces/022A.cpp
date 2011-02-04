#include <cstdio>

int main(void){
	int n, t, x = 128, y = 128;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		if(t < x) y = x, x = t;
		else if(t != x && t < y) y = t;
	}
	if(y == 1 << 7) puts("NO");
	else printf("%d\n", y);
	return 0;
}
