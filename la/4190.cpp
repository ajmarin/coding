#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1024;
int v[N], prime[N];
long long phi[N];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		long long ans = 1;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			prime[i] = i > 0;
		}
		sort(v, v + n);
		for(int i = 0; i < n; ++i) phi[i] = v[i];
		for(int i = 0; i < n; ++i){
			if(prime[i])
				for(int j = i; j < n; ++j)
					if(!(v[j] % v[i])){
						prime[j] = 0;
						phi[j] *= v[i] - 1;
						phi[j] /= v[i];
					}
			ans = (ans * phi[i]) % 1000000007;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

