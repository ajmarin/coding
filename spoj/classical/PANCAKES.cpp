#include <algorithm>
#include <cstdio>
using namespace std;
int bought[64];
int main(void){
	for(int n, r, z; scanf("%d %d", &n, &r) == 2 and (n or r); ){
		int idx = 0, maxp = 0;
		for(int i = 0; i < n; ++i) scanf("%d", bought + i), bought[i] *= 10;
		for(int i = 0; i < r; ++i){
			int p = 1 << 29, t;
			for(int j = 0; j < n; ++j){
				scanf("%d", &z);
				if(not z) continue;
				t = bought[j] / z;
				p = p > t ? t : p;
			}
			if(p > maxp){ idx = i; maxp = p; }
		}
		printf("%d %d\n", ++idx, maxp);
	}
	return 0;
}

