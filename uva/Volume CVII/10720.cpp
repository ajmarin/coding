#include <algorithm>
#include <cctype>
#include <cstdio>

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

int z[10048];

inline int min(int a, int b){ return a < b ? a : b; }

int main(void){
	for(int n; RI(n) && n; ){
		int ok = 1, sum = 0;
		for(int i = 0; i < n; ++i){
			RI(z[i]);
			ok &= z[i] >= 0 && z[i] < n;
			sum ^= z[i] & 1;
		}
		ok &= sum == 0;
		sum = 0;
		std::sort(z, z + n);
		std::reverse(z, z + n);
		for(int i = 0; ok && i < n; ++i){
			sum += z[i];
			int test = i * (i + 1);
			for(int j = i + 1; j < n; ++j) test += min(i + 1, z[j]);
			ok &= sum <= test;
		}
		puts(ok ? "Possible" : "Not possible");
	}
	return 0;
}

