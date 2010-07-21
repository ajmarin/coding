#include <cstdio>

int main(void){
	int k, n, t, x; scanf("%d", &t);
	for(int cnum = 0; cnum++ < t; ){
		x = 0;
		scanf("%d", &n);
		while(n--) scanf("%d", &k), x = x > k ? x : k;
		printf("Case %d: %d\n", cnum , x);
	}
	return 0;
}
