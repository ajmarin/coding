#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	long long num = 600851475143LL;
	int ans = 0;
	for(int div = 3; ; div += 2)
		if(!(num % div)){
			do { num /= div; } while (!(num % div));
			if(num == 1){
				ans = div;
				break;
			}		
		}		
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
