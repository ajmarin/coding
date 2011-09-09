#include <cctype>
#include <cstdio>

#define FOR(i,n)	for(int i = 0; i < n; ++i)
#define FORI(i,s,n)	for(int i = s; i < n; ++i)
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
int m[400][805];
int max_sum, n;

void try_sum(int sum, int row, int left, int right){
	if(row < 0 || row >= n) return;
	if(left < 1 || right >= ((row+1)<<1)) return;
	sum += m[row][right] - m[row][left - 1];
	if(sum > max_sum) max_sum = sum;
	if(right & 1) try_sum(sum, row + 1, left, right + 2);
	else try_sum(sum, row - 1, left - 2, right);
}

int main(void){
	for(int cnum(1); RI(n) == 1 && n; ){
		max_sum = 1 << 31;
		FOR(i, n){
			m[i][0] = 0;
			int lim_j = (i + 1) << 1;
			FORI(j, 1, lim_j){
				RI(m[i][j]);
				m[i][j] += m[i][j - 1];
			}
		}
		FOR(i, n){
			int lim_j = (i + 1) << 1;
			FORI(j, 1, lim_j) try_sum(0, i, j, j);
		}
		printf("%d. %d\n", cnum++, max_sum);
	}
			
	return 0;
}

