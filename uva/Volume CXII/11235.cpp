#include <cstdio>
const int N = 200048;
int begin[N], end[N], v[N];

inline int min(int a, int b){ return a < b ? a : b; }
inline int max(int a, int b){ return a > b ? a : b; }

struct node {
	int b, e, m, v;
	node *left, *right;
} nodes[N << 2];

void init(node *n, int idx, int b, int e){
	int z = v[n->m = ((n->b = b) + (n->e = e)) >> 1];
	if(b != e){
		n->left = nodes + (idx << 1) + 1;
		n->right = nodes + (idx << 1) + 2;
		init(n->left, n->left - nodes, n->b, n->m);
		init(n->right, n->right - nodes, n->m + 1, n->e);
		n->v = max(n->left->v, n->right->v);
		n->v = max(n->v, min(end[z], n->e) - max(begin[z], n->b) + 1);
	} else {
		n->left = n->right = NULL;
		n->v = 1;
	}
}

int query(node *n, int i, int j){
	if(i > n->e || j < n->b) return 0;
	if(i <= n->b && n->e <= j) return n->v;
	int z = max(query(n->left, i, j), query(n->right, i, j));
	return max(z, min(end[v[n->m]], j) - max(begin[v[n->m]], i) + 1);
}

int main(void){
	for(int n, q; scanf("%d %d", &n, &q) == 2; ){
		for(int i = 0, p = 200001; i < n; ++i){
			scanf("%d", v + i);
			v[i] += 100000;
			if(v[i] != p){
				end[p] = i - 1;
				begin[v[i]] = i;
			}
			p = v[i];
		}
		end[v[n - 1]] = n - 1;
		init(nodes, 0, 0, n - 1);
		for(int a, b, i = 0; i < q; ++i){
			scanf("%d %d", &a, &b);
			printf("%d\n", query(nodes, --a, --b));
		}
	}
	return 0;
}

