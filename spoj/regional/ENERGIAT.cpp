#include <cctype>
#include <cstdio>

#define FF 20
#define FORI(a, b, c) for(int a = b; a < c; ++a)
#define FOR(a, b) FORI(a, 0, b)
#define IN getc( stdin )
#define MIN(a,b) ((a)<(b)?(a):(b))
#define PP 5000

int c[PP][FF];
int dp[PP + 5][FF];
void fastint( register int *n ){
	register char c = 0;
	*n = 0;
	while(!isdigit(c)) c = IN;
	while(isdigit(c)) *n = *n * 10 + c - '0', c = IN;
}
int main(void){
	int F, P, E, A;
	int a, b, min;
	while(scanf("%d %d %d %d", &F, &P, &E, &A) && F){
		E *= A;
		FOR(i, P) FOR(j, F){
			fastint(&a), fastint(&b);
			c[i][j] = a * b;
		}
		dp[0][0] = 0;
		FORI(i, 1, F) dp[0][i] = E;
		FORI(i, 1, P + 1){
			int p = i - 1;
			int *pc = c[p], *pdp = dp[p], *pdpi = dp[i];
			min = 0x7fffffff;
			FOR(j, F) {
				*pdpi = *pdp++ + *pc++;
				min = MIN(*pdpi, min);
				++pdpi;
			}
			min += E; pdpi = dp[i];
			FOR(j, F) *pdpi++ = MIN(*pdpi, min);
		}
		printf("%d\n", min - E);
	}
	return 0;
}

