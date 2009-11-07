#include <cstdio>

#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define FOR(a,b) FORI(a,0,b)
#define IN getc( stdin )
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NN 1005

char X[1032], Y[1032];
int A, B, XLEN, YLEN;
int SR[NN][NN], CS[NN][NN], MX[NN][NN];

int main(void){
	int K;
	FOR(i, NN) SR[i][0] = SR[0][i] = CS[i][0] = CS[0][i] = MX[0][i] = MX[i][0] = 0;
	while(scanf("%d\n",&K) && K){
		register char *p = X;
		while((*p++ = IN) != 10);
		XLEN = p - X; *--p = 0; p = Y;
		while((*p++ = IN) != 10);
		YLEN = p - Y; *--p = 0;
		char *w1 = X, *w2;
		register int *cs, *mx, *sr;
		FORI(i, 1, XLEN){
			cs = CS[i] + 1; mx = MX[i] + 1; sr = SR[i] + 1;
			w2 = Y;
			FORI(j, 1, YLEN){
				*cs = *sr = 0;
				A = *(mx - 1005), B = *(mx - 1);
				*mx = MAX(A, B);
				if(*w1 == *w2++){
					*cs = *(cs - 1006) + 1;
					if(*cs >= K){
						A = *(mx - 1006 * K) + K, B = *(sr - 1006) + 1;
						*sr = MAX(A, B);
						*mx = MAX(*mx, *sr);
					}
				}
				cs++; sr++; mx++;
			}
			w1++;
		}
		printf("%d\n",MX[XLEN - 1][YLEN - 1]);
	}
	return 0;
}
		
