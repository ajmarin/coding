#include <cmath>
#include <cstdio>
#include <ctime>


const int MAX = 10000;
int sq[MAX];
int sqr(int x){ return x * x; }
bool is_sqr(int x){ return sqr(floor(sqrt(x + .5))) == x; }
bool valid(int x, int i, int j){
	return is_sqr(j - i) && is_sqr(x - j) && is_sqr(x - (i + j));
}
int main(void){
	clock_t ini = clock();
	int ans = -1; bool found = false;
	for(int i = 0; i < MAX; ++i) sq[i] = i * i;
	for(int x = 1; !found; ++x)
		for(int j = 1; sq[j] < x; ++j){
			if(!is_sqr(2*x - sq[j])) continue;
			for(int k = j + 1; sq[k] < x; ++k)
				if(valid(x << 1, sq[j], sq[k])){
					found = true;
					ans = 3*x - sq[j] - sq[k];
					printf("(%d, %d, %d)\n", x, x - sq[j], x - sq[k]);
					break;
				}
			if(found) break;
		}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

