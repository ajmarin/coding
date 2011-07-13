#include <cmath>
#include <cstdio>
#define FOR(i,n)		for(int i = 0; i < n; ++i)
#define FORI(i,f,n)		for(int i = f; i < n; ++i)
#define FORS(i,f,n,s)	for(int i = f; i < n; i += s)
#define MAX(a,b)		((a) > (b) ? (a) : (b))
const int MAXP = 1<<16, ROOT = 1<<8;
int pl[MAXP/10], pc = 0;
bool prime[MAXP];
bool segprime[1000048];
int main(void){
	FOR(i, MAXP) prime[i] = i > 1;
	FORS(i, 4, MAXP, 2) prime[i] = false;
	FORS(i, 3, ROOT, 2) if(prime[i]){
		FORS(j, i*i, MAXP, i<<1) prime[j] = false;
	}
	FOR(i, MAXP) if(prime[i]) pl[pc++] = i;// printf("%d\n", i);
	int t; scanf("%d", &t);
	while(t--){
		int a, b, first, from, limit, range, step, to;
		scanf("%d %d", &from, &to);
		range = to - from + 1;
		limit = int(floor(sqrt(to)));
		FOR(i, range) segprime[i] = true;
		if(from <= 2 && to >= 2) puts("2");
		FORI(i, 1, pc){
			if(pl[i] > limit) break;
			a = pl[i] * pl[i];
			b = ((from + pl[i] - 1)/ pl[i]) * pl[i];
			if(!(b & 1)) b += pl[i];
			first = MAX(a, b);
			step = pl[i] << 1;
			FORS(j, first - from, range, step) segprime[j] = false;
				//printf("%d isnt prime due to %d\n", j + from, pl[i]);
		}
		FORS(i, !(from & 1), range, 2) if(segprime[i]) printf("%d\n", i + from);
	}

	return 0;
}


