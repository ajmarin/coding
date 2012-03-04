#include <cstdio>
#define FOR(i,s,n) for(int i(s); i<n; ++i)

char w[128];
int z[128][2550] = {1}, l, s, t;

int main(void){
	FOR(i, 1, 101) FOR(j, 0, 2501) FOR(k, 0, 26) 
		z[i][j + k] = (z[i - 1][j] + z[i][j + k]) % 1000000007;
	for(scanf("%d", &t); t--; ){
		scanf("%s", w);
		for(l = s = 0; w[l]; ++l) s += w[l] - 'a';
		printf("%d\n", z[l][s] - 1);
	}
	return 0;
}

