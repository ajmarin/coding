#include <algorithm>
#include <cstdio>
using namespace std;
int v[128];
int main(void){
	for(int k; scanf("%d", &k) == 1; ){
		int ans = 0;
		for(int i = 0; i < k; ++i) scanf("%d", v + i);
		sort(v, v + k);
		for(int i = 0; i < (k + 1) >>1; ++i) ans += (1 + v[i]) >> 1;
		printf("%d\n", ans);
	}
	return 0;
}

