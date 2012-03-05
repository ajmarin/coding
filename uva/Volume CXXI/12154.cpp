#include <cstdio>

bool z[10000001];
int v[10048];
int main(void){
	for(int n; scanf("%d", &n) == 1 && n; ){
		int ans = -1, sum = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d", v + i);
			sum += v[i];
		}
		for(int i = 0; i < sum; ++i) z[i] = false;
		for(int i = sum =  0; i < n; ++i) z[sum += v[i]] = true;
		for(int i = n; ans == - 1 && i >= 3; i--) if(!(sum % i)){
			int b = 0, w = sum / i;
			for(int s = 0; b <= w; ++s){
				bool good = true;
				for(int j = b; good && j < sum; j += w) good &= z[j];
				if(good){
					ans = n - i;
					break;
				}
				b += v[s];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

