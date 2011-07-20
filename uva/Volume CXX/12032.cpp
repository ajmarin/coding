#include <cctype>
#include <cstdio>
/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
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
	int t; readint(t);
	for(int cnum = 0, n; cnum++ < t; ){
		readint(n);
		int cs = 0, ms = 0;
		for(int i = 0, p = 0, z; i++ < n; p = z){
			readint(z);
			int dist = z - p;
			if(cs == dist) --cs;
			else if(cs < dist) cs = dist > ms ? (ms = dist) - 1 : ++ms;
		}
		printf("Case %d: %d\n", cnum, ms);
	}
	return 0;
}

