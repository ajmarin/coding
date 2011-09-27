#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
int m[8][8], v[8];
int best, n;

void bt(int mask, int k){
	if(k == n){
		int sum = 0;
		FOR(i, n) sum += m[i][v[i]];
		if(sum < best) best = sum;
		return;
	}
	FOR(i, n){
		if(mask & (1 << i)) continue;
		v[k] = i;
		bt(mask | (1 << i), k + 1);
	}
}

int main(void){
	int t; scanf("%d", &t);
	while(t-- && scanf("%d", &n) == 1){
		best = 1 << 30;
		FOR(i, n) FOR(j, n) scanf("%d", &m[i][j]);
		bt(0, 0);
		printf("%d\n", best);
	}
	return 0;
}

