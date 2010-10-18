#include <algorithm>
#include <cstdio>
using namespace std;
int main(void){
	for(int ans, n, p; scanf("%d", &n) && n; ){
		scanf("%d", &p);
		ans = abs(p - n);
		while(scanf("%d", &p) && p) ans = __gcd(ans, abs(p - n));
		printf("%d\n", ans);
	}
	return 0;
}

