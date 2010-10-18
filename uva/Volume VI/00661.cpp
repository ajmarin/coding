#include <cstdio>
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FOR(a,b)	FORI(a,0,b)
int on[32], p[32];
const char *fuse[2] = {"Fuse was not blown.", "Fuse was blown."};
int max(int x, int y){ return x > y ? x : y; }
int main(void){
	for(int c, cs = 0, m, n, t; scanf("%d %d %d", &n, &m, &c) == 3; ){
		if(!(c || m || n)) break;
		int b = 0, maxpc = 0, pc = 0;
		FOR(i, n) scanf("%d", &p[i]), on[i] = 0;
		FOR(i, m){
			scanf("%d", &t); --t;
			if(on[t]) pc -= p[t];
			else pc += p[t];
			on[t] = 1 - on[t];
			b |= pc > c;
			maxpc = max(maxpc, pc);
		}
		printf("Sequence %d\n", ++cs);
		puts(fuse[b]);
		if(!b) printf("Maximal power consumption was %d amperes.\n", maxpc);
		putc(10, stdout);
	}
	return 0;
}

