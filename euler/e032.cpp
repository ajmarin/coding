#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

char dc[11];
#define CD(x) while(x){ ++dc[x % 10], x /= 10; }
bool pandigital(int a, int b, int c){
	strcpy(dc, "0000000000");
	CD(a); CD(b); CD(c);
	return !strcmp(dc, "0111111111");
}
bool is_pandigital_product(int k){
	for(int i = 2; ; ++i)
		if(i * i > k) return 0;
		else if(!(k % i) && pandigital(i, k/i, k)) return 1;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 1000; i < 10000; ++i)
		if(is_pandigital_product(i)) ans += i;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

