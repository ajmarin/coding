#include <cmath>
#include <cstdio>
#include <ctime>

bool over = 0, v[10] = {0};
long long ans = 0;
void r(long long k, int d){
	if(over) return;
	if(d == 11){
		if(++ans == 1000000){
			ans = k;
			over = 1;
			return;
		}
	}
	for(int i = 0; i < 10; ++i)
		if(!v[i]){
			v[i] = 1;
			r(k * 10 + i, d + 1);
			if(over) return;
			v[i] = 0;
		}
}
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < 10; ++i) r(i, 1);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}

