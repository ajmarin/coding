#include <cstdio>
int main(void){
	int t, x, y; scanf("%d", &t);
	while(t--){
		scanf("%d %d", &x, &y);
		if(x != y && x - y != 2) puts("No Number");
		else printf("%d\n", x + y - (y & 1));
	}
	return 0;
}
