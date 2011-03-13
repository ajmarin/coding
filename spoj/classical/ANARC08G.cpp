#include <cstdio>
#define FOR(i,n) for(int i = 0; i < n; ++i)
const int N = 1024;
int b[N];
int main(void){
	for(int cnum = 0, n, z; scanf("%d", &n) == 1 && n; ){
		int sum = 0;
		FOR(i, n) b[i] = 0;
		FOR(i, n) FOR(j, n){
			scanf("%d", &z);
			if(z){
				b[j] += z;
				b[i] -= z;
				sum += z;
			}
		}
		printf("%d. %d ", ++cnum, sum);
		sum = 0;
		FOR(i, n) if(b[i] > 0) sum += b[i];
		printf("%d\n", sum);
	}
	return 0;
}

