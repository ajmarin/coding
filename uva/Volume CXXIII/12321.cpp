#include <algorithm>
#include <cctype>
#include <cstdio>
using namespace std;

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

struct interval {
	int b, e;
	bool operator<(const interval& i) const { 
		return b < i.b || (b == i.b && e < i.e);
	}
} d[10048];
int main(void){
	for(int n, z; (RI(z) + RI(n)) == 2 && (n || z); ){
		for(int a, b, i = 0; i < n; ++i){
			RI(a), RI(b);
			d[i].b = a - b;
			d[i].e = a + b;
		}
		sort(d, d + n);
		int at = 0, discard = n, idx, newat = 0;
		for(int i = 0, j; i < n; ){
			idx = -1;
			for(j = i; d[j].b <= at && j < n; ++j) if(d[j].e >= newat){
				newat = d[j].e;
				idx = j;
			}
			--discard;
			at = newat;
			if(idx == -1 || at >= z) break;
			i = j;
		}
		printf("%d\n", at >= z ? discard : -1);
	}
	return 0;
}

