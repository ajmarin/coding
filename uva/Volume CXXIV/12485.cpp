#include <cstdio>

int v[10048];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int ans = 1, sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			sum += v[i];
		}
		if(!(sum % n)){
			sum /= n;
			for(int i = 0; i < n; ++i)
				ans += v[i] < sum ? sum - v[i] : 0;
			printf("%d\n", ans);
		} else puts("-1");

	}
	return 0;
}

