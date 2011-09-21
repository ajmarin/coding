#include <cctype>
#include <cstdio>

int left[10048], right[10048];

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

int main(void){
	for(int n, m; (RI(n) + RI(m) == 2) && (n || m); ){
		int z;
		for(int i = 0; i < n; ++i){
			RI(z), RI(z), RI(left[i]), RI(right[i]);
			right[i] += left[i];
		}
		for(int i = 0; i < m; ++i){
			int ans = 0;
			RI(left[n]), RI(right[n]);
			right[n] += left[n];
			for(int j = 0; j < n; ++j)
				ans += !(left[n] >= right[j] || right[n] <= left[j]);
			printf("%d\n", ans);
		}
	}
	return 0;
}

