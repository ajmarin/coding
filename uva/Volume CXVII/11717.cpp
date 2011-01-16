#include <cstdio>

int main(void){
	int i, k, n, t, x;
	int ign, ina, act;
	scanf("%d", &t);
	for(int cnum = 0; cnum < t; ){
		ign = ina = act = 0;
		scanf("%d %d %d", &n, &i, &k);
		for(int c = 0; c < n; ++c) {
			scanf("%d", &x);
			if(x < act) ign++;
			else if(x >= act + i){
				ina++;
				act = x + k;
			}
			if(x > act) act = x;
		}
		printf("Case %d: %d %d\n", ++cnum, ina, ign);
	}
	return 0;
}
	