#include <cctype>
#include <cstdio>

const int NN = 20048;
int c[2][2];

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

int min(int a, int b){ 
	return a < b ? a : b;
}

int oh(int x, int l, int r){
	if(x < l) return l - x;
	if(x > r) return x - r;
	return 0;
}

int ep(int x, int l, int r){
	if(x < l) return l;
	if(x > r) return r;
	return x;
}

int main(void){
	int e1, e2, l, o1, o2, pl, pr, r;
	for(int n; RI(n) && n; ){
		pl = pr = 1;
		c[0][0] = c[0][1] = 0;
		for(int i = 1; i <= n; ++i){
			RI(l), RI(r);
			o1 = c[!(i & 1)][0] + oh(pl, l, r) + !!(i - 1);
			o2 = c[!(i & 1)][1] + oh(pr, l, r) + !!(i - 1);
			e1 = ep(pl, l, r);
			e2 = ep(pr, l, r);
			c[i & 1][0] = min(o1 + (r << 1) - e1 - l, o2 + (r << 1) - e2 - l);
			c[i & 1][1] = min(o1 + e1 + r - (l << 1), o2 + e2 + r - (l << 1));
			pl = l;
			pr = r;
		}
		printf("%d\n", min(c[n & 1][0] + n - l, c[n & 1][1] + n - r));
	}
	return 0;
}

