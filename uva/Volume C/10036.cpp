#include <cstdio>
bool p[2][100];
int mod(int n, int k){
	int r = n % k;
	return r > -1 ? r : -r;
}
int main(void){
	int k, t, n, z;
	bool *b, *c;
	for(scanf("%d", &t); t--; ){
		scanf("%d %d", &n, &k);
		for(int i = 0; i < k; ++i) p[0][i] = !i;
		for(int i = 1; i <= n; ++i){
			scanf("%d", &z);
			b = p[!(i&1)], c = p[i&1];
			for(int j = 0; j < k; ++j) c[j] = 0;
			for(int j = 0; j < k; ++j){
				if(b[j]){
					c[mod(j + z, k)] = 1;
					c[mod(j - z, k)] = 1;
				}
			}
		}
		puts(c[0] ? "Divisible" : "Not divisible");
	}
	return 0;
}

