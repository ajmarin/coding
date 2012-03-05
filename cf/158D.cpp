#include <cstdio>

int gsum[10048], v[20096];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			sum += v[i];
		}
		for(int i = 2; i < n; ++i) if(!(n % i)){
			if(n / i < 3) break;
			int maxval = 1 << 31;
			for(int j = 0; j < i; ++j) gsum[j] = 0;
			for(int j = 0; j < n; ++j) gsum[j % i] += v[j];
			for(int j = 0; j < i; ++j) if(gsum[j] > maxval) maxval = gsum[j];
			if(maxval > sum) sum = maxval;
		}
		printf("%d\n", sum);
	}
	return 0;
}

