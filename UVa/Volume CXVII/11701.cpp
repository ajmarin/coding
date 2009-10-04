#include <cstdio>
#include <cmath>

using namespace std;

#define PREC 17
#define EPS 1E-7
#define FORI(a,b,c) for(int a = b; a < c; ++a)

double p[50];
int main(void){

	double div = 3.;
	FORI(i, 1, PREC){
		p[i] = (2/div);
		div *= 3.;
	}
	double N;
	while(scanf("%lf",&N)==1){
		for(int i = 1; i < PREC && N > EPS; i++) N -= p[i] * (N - p[i] > 0.);
		(N > EPS)? puts("NON-MEMBER") : puts("MEMBER");
	}
	return 0;
}

