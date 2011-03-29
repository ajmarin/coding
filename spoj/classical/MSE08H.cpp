#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1024;
int phi[N], v[N];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		long long ans = 1;
		for(int i = 0; i < n; ++i) scanf("%d", v + i);
		sort(v, v + n);
		for(int i = 0; i < n; ++i) phi[i] = v[i];
		for(int i = 1; i < n; ++i){
			if(phi[i] == v[i])
				for(int j = i; j < n; ++j)
					if(!(v[j] % v[i])){
						phi[j] /= v[i];
						phi[j] *= v[i] - 1;
					}
			ans = (ans * phi[i]) % 1000000007;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

