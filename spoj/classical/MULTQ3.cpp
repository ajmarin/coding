#include <cctype>
#include <cstdio>

#define LEFT(x) (x << 1)
#define RIGHT(x) (1 + (x << 1))

/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */
struct triple {
	int c[3];
	triple(int _a = 0, int _b = 0, int _c = 0){
		c[0] = _a; c[1] = _b; c[2] = _c;
	}
	triple operator+(const triple& t) const {
		return triple(c[0] + t.c[0], c[1] + t.c[1], c[2] + t.c[2]);
	}
	void rotate(){
		*this = triple(c[2], c[0], c[1]);
	}
};

struct interval {
	int l, r;
	triple cnt;
	int u;
} d[282144];

void init_interval(int idx, int left, int right){
	interval *i = d + idx;
	int m = ((i->l = left) + (i->r = right)) >> 1;
	i->u = 0;
	i->cnt = triple(right - left + 1, 0, 0);
	if(left >= right) return;
	init_interval(LEFT(idx), left, m);
	init_interval(RIGHT(idx), m + 1, right);
}

void refresh(int idx){
	interval *i = d + idx;
	if(!(i->u % 3)) return;
	int up = i->u % 3;
	i->u = 0;
	i->cnt.rotate();
	if(up == 2) i->cnt.rotate();
	if(i->l >= i->r) return;
	d[LEFT(idx)].u += up;
	d[RIGHT(idx)].u += up;
}

triple query(int idx, int b, int e){
	interval *i = d + idx;
	if(b > i->r || e < i->l) return triple();
	refresh(idx);
	if(b <= i->l && e >= i->r) return i->cnt;
	return query(LEFT(idx), b, e) + query(RIGHT(idx), b, e);
}

void update(int idx, int b, int e){
	interval *i = d + idx;
	refresh(idx);
	if(b > i->r || e < i->l) return;
	if(b <= i->l && e >= i->r){
		i->u += 1;
		refresh(idx);
	} else {
		update(LEFT(idx), b, e);
		update(RIGHT(idx), b, e);
		i->cnt = d[LEFT(idx)].cnt + d[RIGHT(idx)].cnt;
	}
}

int main(void){
	for(int n, m; RI(n) + RI(m) == 2 && (m || n); ){
		int b, e, op;
		init_interval(1, 1, n);
		for(int i = 0; i < m; ++i){
			RI(op), RI(b), RI(e);
			++b; ++e;
			if(op == 1){
				triple ans = query(1, b, e);
				printf("%d\n", ans.c[0]);
			} else update(1, b, e);
		}
		puts("");
	}
	return 0;
}

