#include <cstdio>

#define FOR(i, n) for(int i = 0; i < n; ++i)

int main(void){
	int t, v[32]; scanf("%d", &t);
	for(int n, z; t-- && scanf("%d", &z) == 1; ){
		scanf("%d", &n);
		FOR(i, n) scanf("%d", v + i);
		bool possible = false;
		FOR(i, 1<<n){
			int sum = 0;
			FOR(j, n) if(i & (1 << j)) sum += v[j];
			if(sum == z){
				possible = true;
				break;
			}
		}
		puts(possible ? "YES" : "NO");
	}
	return 0;
}

