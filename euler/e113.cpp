#include <cmath>
#include <cstdio>
#include <ctime>

#define FORI(i,s,n)	for(int i = s; i < n; ++i)
#define FORD(i,s,n)	for(int i = s; i > n; --i)
const int pwr = 100;
long long dec[10][100], inc[10][100];
int main(void){
	clock_t ini = clock();
	long long ans = 0;
	dec[0][0] = inc[0][0] = 0;
	FORI(i, 1, 10) dec[i][0] = inc[i][0] = 1;
	FORI(d, 1, 100){
		long long dec_sum = 0, inc_sum = 0;
		FORI(i, 0, 10) inc[i][d] += inc_sum += inc[i][d - 1];
		FORD(i, 9, -1) dec[i][d] += dec_sum += dec[i][d - 1];
	}
	FORI(i, 0, 10) FORI(j, 0, 100) ans += dec[i][j] + inc[i][j];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans - 9 * pwr);
	return 0;
}
