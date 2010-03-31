#include <cstdio>
#include <cstring>
#include <ctime>
#define MAX 1000000
bool p[MAX];
int main(void){
	clock_t ini = clock();
	memset(p, 1, sizeof(p));
	int ans = 1000, c = 1;
	for(int i = 4; i < MAX; i += 2) p[i] = 0;
	for(int i = 3; i < 1001; i += 2)
		if(p[i]){
			++c;
			for(int j = i * i; j < MAX; j += i) p[j] = 0;
		}
	while(c < 10001) c += p[++ans];
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
