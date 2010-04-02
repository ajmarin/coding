#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <set>

using namespace std;

#define MAX 7071
#define MAX_SQRT 87
#define MAX_SUM 50000000

bool p[MAX];
int ans, c = 0, primes[1000][4];
set < int > s;
void r(int d, int sum){
	if(d < 3){
		d = d + 1;
		for(int i = 0; ; ++i){
			int s = sum + primes[i][d];
			if(s > MAX_SUM) break;
			r(d, s);
		}
	}
	else s.insert(sum);
}
void add(int p){
	primes[c][0] = p;
	for(int i = 1; i < 4; ++i) primes[c][i] = primes[c][i - 1] * p;
	c++;
}
int main(void){
	clock_t ini = clock();
	/* Erasthostenes' Sieve */
	memset(p, 1, MAX); add(2);
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < MAX_SQRT; i += 2)
		if(p[i]) {
			add(i);
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	for(int i = MAX_SQRT; i < MAX; i += 2) if(p[i]) add(i);
	for(int i = 0; i < c; ++i) r(1, primes[i][1]);
	ans = s.size();
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
