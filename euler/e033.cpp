#include <cmath>
#include <cstdio>
#include <ctime>

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
void simplify(int *a, int *b){
	int g = gcd(*a, *b);
	*a /= g;
	*b /= g;
}
bool test(int a, int b, int x, int y){
	simplify(&a, &b);
	return a == x && b == y;
}
bool curious(int a, int b){
	int td, tn, x = a, y = b;
	int d1a, d2a, d1b, d2b;
	bool is_curious = 0;
	simplify(&x, &y);
	d1a = a / 10; d2a = a % 10;
	d1b = b / 10; d2b = b % 10;
	if(d1a == d1b) is_curious |= test(d2a, d2b, x, y);
	if(d1a == d2b) is_curious |= test(d2a, d1b, x, y);
	if(d2a == d1b) is_curious |= test(d1a, d2b, x, y);
	if(d2a == d2b) is_curious |= test(d1a, d1b, x, y);
	return is_curious;
}

int main(void){
	clock_t ini = clock();
	int num = 1, ans = 1;
	for(int i = 10; i < 100; ++i)
		if(i % 10) for(int j = i + 1; j < 100; ++j)
			if(j % 10 && curious(i, j)){
				int x = i, y = j;
				simplify(&x, &y);
				printf("Curious: %d/%d = %d/%d\n", i, j, x, y);
				num *= x;
				ans *= y;
			}
	simplify(&num, &ans);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

