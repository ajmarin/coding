#include <algorithm>
#include <cstdio>
using namespace std;
#define NB 51
#define NF 1001
int t[NB][NF];

int drop(int b, int f) {
	if(t[b][f] != -1) return t[b][f];
	int m = f;
	for(int i = 1; i <= f; ++i){
		int x = drop(b - 1, i - 1), y = drop(b, f - i);
		m = min(m, 1 + max(x, y));
	}
	return t[b][f] = m;
}

int main(void){
	for(int i = 1; i < NF; ++i) t[1][i] = i;
	for(int i = 2; i < NB; ++i){
		for(int j = 2; j < NF; ++j) t[i][j] = -1;
		t[i][1] = 1;
		t[i][0] = 0;
	}
	int z; scanf("%d", &z);
	for(int b, c, n; scanf("%d %d %d", &c, &b, &n) == 3; )
		printf("%d %d\n", c, drop(b, n));
	return 0;
}

