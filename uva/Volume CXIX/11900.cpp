#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	int cnum = 0;
	for(int n, p, q, z; t-- && scanf("%d %d %d", &n, &p, &q) == 3; ){
		int ans = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", &z);
			if(p && q >= z){
				--p;
				q -= z;
				++ans;
			}
		}
		printf("Case %d: %d\n", ++cnum, ans);
	}
	return 0;
}

