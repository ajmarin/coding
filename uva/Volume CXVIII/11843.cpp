#include <algorithm>
#include <cstdio>
using namespace std;
#define NS 21
#define NN 1001
int t[NS][NN];

int guess(int b, int f) {
	if(t[b][f] != -1) return t[b][f];
	int m = f;
	for(int i = 1; i <= f; ++i){
		int x = guess(b - 1, i - 1), y = guess(b, f - i);
		m = min(m, 1 + max(x, y));
	}
	return t[b][f] = m;
}

int main(void){
	for(int i = 1; i < NN; ++i) t[1][i] = i;
	for(int i = 2; i < NS; ++i){
		for(int j = 2; j < NN; ++j) t[i][j] = -1;
		t[i][1] = 1;
		t[i][0] = 0;
	}
	int z; scanf("%d", &z);
	for(int n, s; scanf("%d %d", &n, &s) == 2; printf("%d\n", guess(s, n)));
	return 0;
}

