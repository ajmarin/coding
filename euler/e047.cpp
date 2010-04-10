#include <cmath>
#include <cstdio>
#include <ctime>

#define MAX 1000000
#define SQMAX 1000
int ans = 0, c = 0, pl[100000];
bool p[MAX];
void test(int k){
	if(c == 4){ ans = k - 4; return; }
	int div = 0;
	for(int i = 0; ; ++i){
		int x = pl[i];
		if(x * x > k) break;
		if(!(k % x)){
			div++; k /= x;
			while(!(k % x)) k /= x;
		}
	}
	div += k != 1;
	if(div == 4) c++;
	else c = 0;
}
int main(void){
	clock_t ini = clock();
	int c = 1;
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
	for(int i = 1; !ans; ++i) test(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

