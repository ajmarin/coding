
#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 1000000
#define SQMAX 1000
int dsq[1000], pl[100000];
bool p[MAX];
bool cant(int x){
	for(int i = 1; dsq[i] < x; ++i)
		if(p[x - dsq[i]]) return 0;
	return 1;
}
int main(void){
	clock_t ini = clock();
	int ans = 0, c = 1;
	for(int i = 1; i < 1001; ++i) dsq[i] = 2 * i * i;
	for(int i = 0; i < MAX; ++i) p[i] = 1;
	p[0] = p[1] = 0; pl[0] = 2;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < SQMAX; i += 2)
		if(p[i]){
			pl[c++] = i;
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	for(int i = SQMAX + !(SQMAX & 1); i < MAX; i += 2)
		if(p[i]) pl[c++] = i;
	for(int k = 9; !ans; k += 2) if(!p[k] && cant(k)) ans = k;

	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

