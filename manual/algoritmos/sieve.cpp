#include <cstring>

#define MAXN  100000000  /* valor maximo de N */
#define P1    1562501    /* = ceil(MAXN/64) + 1 */
#define P2    50000000   /* = ceil(MAXN/2) */
#define P3    5000       /* = ceil(ceil(sqrt(MAXN))/2) */

unsigned s[P1];

#define GET(b) ((s[(b) >> 5] >> ((b) & 31)) & 1)

void make() {
	register unsigned i, j, k;
	memset(s, 0, sizeof(s));
	for(k = 1; k <= P3; k++)
		if(GET(k) == 0)
			for(j = 2*k+1, i = 2*k*(k+1); i < P2; i += j)
				s[i >> 5] |= 1 << (i & 31);
}

int isprime(int p) {
	return p == 2 || (p > 2 && (p & 1) == 1 && (GET((p-1) >> 1) == 0));
}
