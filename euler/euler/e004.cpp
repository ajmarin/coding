#include <cstdio>
#include <ctime>

int rev(int x){
	int y = x, z = 0;
	while(y){
		z = z * 10 + (y % 10);
		y /= 10;
	}
	return z;
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int a = 999; a > 1; --a)
		for(int b = a; b > 1; --b){
			int x = a * b, z = rev(x);			
			if(x == z && x > ans) ans = x;
		}				
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
