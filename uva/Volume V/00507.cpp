#include <cstdio>

#define FOR(a,b)	for(int a = 0; a < b; ++a)
#define FORI(a,b,c)	for(int a = b; a < c; ++a)
#define FORD(a,b,c)	for(int a = b; a > c; --a)

int main(void){
	int b, r, v; scanf("%d", &b);
	for(int c = 0; c < b; ){
		scanf("%d", &r);
		int b, bgn = 1, best = 0, e, maxl = -1, sum = 0;
		FORI(i, 1, r) {
			scanf("%d", &v);
			sum += v;
			if(sum < 0){ sum = 0, bgn = i + 1; }
			else if(sum > best || (sum == best && i - bgn > maxl)){
				maxl = i - bgn;
				best = sum;
				b = bgn;
				e = i + 1;
			}
		}
		if(best) 
			printf("The nicest part of route %d is between stops %d and %d\n", ++c, b, e);
		else printf("Route %d has no nice parts\n", ++c);
	}
	return 0;
}

