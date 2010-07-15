#include <cstdio>
int k, n, p, t;
int main(void){
	scanf("%d", &t);
	for(int cnum = 0; cnum < t; ){
		scanf("%d %d %d", &n, &k, &p);
		k--;
		printf("Case %d: %d\n", ++cnum, ((k + p) % n) + 1);
	}
	return 0;
}
