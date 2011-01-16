#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int f1, f2, f3, sum = 0;
	f1 = f2 = 1;
	while(f3 < 4000000){
		f3 = f1 + f2;
		if(!(f3 & 1)) sum += f3;
		f1 = f2;
		f2 = f3;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", sum);
	return 0;
}
