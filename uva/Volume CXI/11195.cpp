#include <algorithm>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; ++i)
int ans, n, row[16];

void bt(int l, int c, int d1, int d2){
	if(l == n){
		++ans;
		return;
	}
	for(int tmp = c | (d1 >> l) | (d2 >> (n - l - 1)) | row[l], x;
			(x = ~tmp & (tmp + 1)) < (1 << n); tmp |= x)
		bt(l + 1, c | x, d1 | (x << l), d2 | (x << (n - l - 1)));
}

int main(void){
	char line[16];
	for(int c = 0; scanf("%d", &n) == 1 && n; ){
		ans = 0;
		FOR(i, n){
			row[i] = 0;
			scanf("%s", line);
			FOR(j, n) row[i] = (row[i] << 1) | (line[j] == '*');
		}
		bt(0, 0, 0, 0);
		printf("Case %d: %d\n", ++c, ans);
	}
	return 0;
}

