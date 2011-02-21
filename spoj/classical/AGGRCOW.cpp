#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100048;
int s[N];
bool possible(int d, int n, int c){
	int cnt = 1;
	for(int b = 0, i = 1; i < n && cnt < c; ++i)
		if(s[i] - s[b] >= d) ++cnt, b = i;
	return cnt == c;
}
int main(void){
	int t; scanf("%d", &t);
	for(int n, c; t-- && scanf("%d %d", &n, &c) == 2; ){
		for(int i = 0; i < n; ++i) scanf("%d", s + i);
		sort(s, s + n);
		int l = 1, m, r = 1 + s[n-1] - s[0];
		while(l < r){
			m = (l + r) >> 1;
			if(possible(m, n, c)) l = m + 1;
			else r = m;
		}
		printf("%d\n", l - !possible(l, n, c));
	}
	return 0;
}

