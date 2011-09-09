#include <cctype>
#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
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
int r[1024];
int main(void){
	for(int cnum(1), n, z; RI(n) == 1 && n; ){
		int opt(0), total(0);
		FOR(i, n) r[i] = 0;
		FOR(i, n) FOR(j, n){
			RI(z);
			r[i] -= z;
			r[j] += z;
			total += z;
		}
		FOR(i, n) if(r[i] > 0) opt += r[i];
		printf("%d. %d %d\n", cnum++, total, opt);
	}
	return 0;
}

