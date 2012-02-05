#include <algorithm>
#include <cstdio>


long long v[100048];
int main(void){
	scanf("%*d");
	for(int C, cnum = 0, K, n; scanf("%d %d %d %lld", &K, &C, &n, v) == 4; ){
		long long sum = 0;
		for(int i = 1; i < n; ++i) v[i] = (K * v[i - 1] + C) % 1000007;
		std::sort(v, v + n);
		for(int i = 1; i < n; ++i){
			sum += (v[i] * i) - v[i - 1];
			v[i] += v[i - 1];
		}
		printf("Case %d: %lld\n", ++cnum, sum);
	}
	return 0;
}

