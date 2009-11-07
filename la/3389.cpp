#include <cstdio>

int main(void){
	int N, T;
	scanf("%d", &T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		int q, d, n, p;
		q = N/25;
		N%= 25;
		d = N/10;
		N%= 10;
		n = N/5;
		N%= 5;
		p = N;
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
				++cnum, q, d, n, p);
	}
	return 0;
}

