#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 104875, NL = 1048576;
char w[NL];
int len[N], lcp[N], pos[N], rpos[N], sp[N];

/* {{{ Interval tree */
#define LEFT(x) (2 * (x - d) + d + 1)
#define RIGHT(x) (2 * (x - d) + d + 2)
struct interval { int left, right, value; } d[3*N];
int init_interval(int left, int right, interval *i = d){
	i -> left = left;
	i -> right = right;
	if(left < right){
		int mid = (left + right) >> 1;
		i -> value = min(
			init_interval(left, mid, LEFT(i)),
			init_interval(mid + 1, right, RIGHT(i))
		);
	} else i -> value = lcp[left];
	return i -> value;
}
int query(int left, int right, interval *i = d){
	if(left > i -> right || i -> left > right) return 1 << 30;
	if(left <= i -> left && i -> right <= right) return i -> value;
	return min(query(left, right, LEFT(i)), query(left, right, RIGHT(i)));
}
/* }}} */

bool cmp(int a, int b){ return strcmp(w + sp[a], w + sp[b]) < 0; }

void compute_lcp(int n){
	lcp[0] = 0;
	for(int i = 1; i < n; ++i){
		int sa = sp[pos[i]];
		int sb = sp[pos[i - 1]];
		lcp[i] = 0;
		while(w[sa] && w[sb] && w[sa++] == w[sb++]) ++lcp[i];
	}
}
int main(void){
	int t; scanf("%d", &t);
	for(int cnum = 0, n; cnum++ < t && scanf("%d", &n) == 1; ){
		int L = 0;
		for(int i = 0; i < n; ++i){
			scanf("%s", w + L);
			sp[i] = L;
			for(len[i] = 0; w[L]; ++len[i]) ++L;
			w[L++] = 0;
			pos[i] = i;
		}
		sort(pos, pos + n, cmp);
		compute_lcp(n);
		init_interval(0, n);
		for(int i = 0; i < n; ++i) rpos[pos[i]] = i;
		int a, b, q;
		scanf("%d", &q);
		printf("Case %d:\n", cnum);
		while(q--){
			scanf("%d %d", &a, &b);
			if(a == b) printf("%d\n", len[--a]);
			else {
				a = rpos[--a];
				b = rpos[--b];
				if(a > b) swap(a, b);
				printf("%d\n", query(a + 1, b));
			}
		}
	}
	return 0;
}

