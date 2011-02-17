#include <cstdio>

int main(void){
	int i, n, t; scanf("%d", &t);
	long long s, z;
	while(t--){
		scanf("%d", &n);
		for(i = s = 0; i < n; ++i) scanf("%lld", &z), s = (s + z) % n;
		puts(s ? "NO" : "YES");
	}
	return 0;
}

