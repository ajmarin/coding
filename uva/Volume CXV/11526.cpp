#include <cmath>
#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(int n; t-- && scanf("%d", &n) == 1; ){
		long long s = 0;
		if(n > 0){
			int L = floor(sqrt(n));
			for(int i = 1, q, pq = n; i <= L; ++i){
				q = n / i;
				s += q + (pq - q) * (i - 1);
				pq = q;
			}
			if(n / L > L) s += L;
		}
		printf("%lld\n", s);
	}
	return 0;
}

