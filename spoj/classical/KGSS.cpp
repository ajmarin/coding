#include <cassert>
#include <cstdio>
#define LEFT(x)		(x<<1)
#define RIGHT(x)	(1+(x<<1))
const int N = 300048;
int v[N];
struct interval { int f, l, r, s; } d[N];
bool cmp(int a, int b){ return v[a] > v[b]; }
bool ok(int x, int b, int e){ return x >= b && x <= e; }
void upd(int idx, int &x1, int &x2){
	if(v[idx] > v[x1]) x2 = x1, x1 = idx;
	else if(idx != x1 && v[idx] > v[x2]) x2 = idx;
}
void init(int idx, int b, int e){
	interval *i = d + idx;
	int m = (b + e) >> 1;
	i->l = b; i->r = e;
	assert(i->l <= i->r);
	i->f = i->s = 0;
	if(b < e){
		int left = LEFT(idx), right = RIGHT(idx);
		init(left, b, m);
		init(right, m + 1, e);
		upd(d[left].f, i->f, i->s);
		upd(d[left].s, i->f, i->s);
		upd(d[right].f, i->f, i->s);
		upd(d[right].s, i->f, i->s);
	} else i->f = b;
}
void update(int idx, int p){
	interval *i = d + idx;
	assert(i->l <= i->r);
	if(p < i->l || p > i->r) return;
	upd(p, i->f, i->s);
	if(i->l < i->r){
		int left = LEFT(idx), right = RIGHT(idx);
		update(LEFT(idx), p), update(RIGHT(idx), p);
		upd(d[left].f, i->f, i->s);
		upd(d[left].s, i->f, i->s);
		upd(d[right].f, i->f, i->s);
		upd(d[right].s, i->f, i->s);
	}
}
void query(int idx, int b, int e, int &x1, int &x2){
	interval *i = d + idx;
	if(b > i->r || e < i->l) return;
	if(ok(i->f, b, e)) upd(i->f, x1, x2);
	if(ok(i->s, b, e)) upd(i->s, x1, x2);
	if(b <= i->l && i->r <= e) return;
	query(LEFT(idx), b, e, x1, x2);
	query(RIGHT(idx), b, e, x1, x2);
}
int main(void){
	int a, b, n, m;
	char op[4];
	scanf("%d", &n);
	v[0] = -1;
	for(int i = 1; i <= n; ++i) scanf("%d", v + i);
	init(1, 1, n);
	for(scanf("%d", &m); m--; ){
		scanf("%s %d %d", op, &a, &b);
		if(op[0] == 'U'){
			v[a] = b;
			update(1, a);
		} else if(op[0] == 'Q'){
			assert(b - a > 0);
			int x1 = 0, x2 = 0;
			query(1, a, b, x1, x2);
			printf("%d\n", v[x1] + v[x2]);
		}
	}
	return 0;
}

