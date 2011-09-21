#include <cctype>
#include <cstdio>
#define max(a,b) ((a<b)?(b):(a))

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
	int c, i, j, pC1, pC2, pL1, pL2, r, temp, v;
	while(RI(r) && RI(c) && r){
		for(pL1 = pL2 = i = 0; i < r; i++){
			for(pC1 = pC2 = j = 0; j < c; j++){
				RI(v);
				temp = pC1;
				pC1 = max(pC1,v+pC2);
				pC2 = temp;
			}
			temp = pL1;
			pL1 = max(pL1,pC1+pL2);
			pL2 = temp;
		}
		printf("%d\n",pL1);
	}
	return 0;
}
