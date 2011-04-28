#include <algorithm>
#include <cstdio>
using namespace std;
int v[100048];
int main(void){
	for(int k, n; scanf("%d %d", &n, &k) == 2; ){
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		int ans = 1 << 20, sum = 0;
		for(int l = 0, r = 0; r < n; ){
			sum += v[r++];
			while(sum >= k && l < r){
				if(r - l < ans) ans = r - l;
				sum -= v[l++];
			}
		}
		printf("%d\n", ans == 1 << 20 ? 0 : ans);
	}
	return 0;
}

