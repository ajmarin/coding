#include <cstdio>
#include <ctime>
#include <set>
using namespace std;
const int LIM = 1000000;
int sod[LIM], mark[LIM];
int chain(int x, int &r){
	mark[x] = x;
	for(int cs = 1, y = x; ; ++cs){
		y = sod[y];
		if(y < r) r = y;
		if(y > LIM) return -1;
		if(mark[y] == x) return y == x ? cs : -1;
		mark[y] = x;
	}
}
int main(void){
	clock_t ini = clock();
	int ans = 0, cst, maxc = 0, s;
	for(int i = 0; i < LIM; ++i) sod[i] = 1, mark[i] = 0;
	for(int i = 2; (i << 1) < LIM; ++i)
		for(int j = i << 1; j < LIM; j += i)
			sod[j] += i;
	for(int i = 1; i < LIM; ++i){
		int c = chain(i, (s = 1 << 30));
		//printf("chain(%d) = %d\n", i, c);
		if(c > maxc){
			cst = i;
			maxc = c;
			ans = s;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d, starting from %d, #%d\n", ans, cst, maxc);
	return 0;
}
	