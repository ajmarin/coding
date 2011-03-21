#include <cstdio>
#define LEFT(x)		(x << 1)
#define RIGHT(x)	(1 + (x << 1))
struct interval {
	int l, m, r, s;
	bool u;
} d[282144];
void init_interval(int idx, int left, int right){
	interval *i = d + idx;
	i->m = ((i->l = left) + (i->r = right)) >> 1;
	i->s = i->u = 0;
	if(left >= right) return;
	init_interval(LEFT(idx), left, i->m);
	init_interval(RIGHT(idx), i->m + 1, right);
}
void refresh(int idx){
	if(!d[idx].u) return;
	interval *i = d + idx;
	i->u = 0;
	i->s = i->r - i->l + 1 - i->s;
	if(i->l >= i->r) return;
	d[LEFT(idx)].u = !d[LEFT(idx)].u;
	d[RIGHT(idx)].u = !d[RIGHT(idx)].u;
}
int query(int idx, int b, int e){
	interval *i = d + idx;
	if(b > i->r || e < i->l) return 0;
	refresh(idx);
	if(b <= i->l && e >= i->r) return i->s;
	return query(LEFT(idx), b, e) + query(RIGHT(idx), b, e);
}
void update(int idx, int b, int e){
	interval *i = d + idx;
	refresh(idx);
	if(b > i->r || e < i->l) return;
	if(b <= i->l && e >= i->r){ i->u = !i->u; refresh(idx); }
	else {
		update(LEFT(idx), b, e), update(RIGHT(idx), b, e);
		i->s = d[LEFT(idx)].s + d[RIGHT(idx)].s;
	}
}
int main(void){
	int a, b, e, n, m; scanf("%d %d", &n, &m);
	init_interval(1, 1, n);
	for(int i = 0; i < m; ++i){
		scanf("%d %d %d", &a, &b, &e);
		if(!a) update(1, b, e);
		else printf("%d\n", query(1, b, e));
	}
}

