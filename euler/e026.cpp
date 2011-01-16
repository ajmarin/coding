#include <cstdio>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int ans, len, max_len = 0, r, r0;
	for(int i = 2; i < 1000; ++i){
		r = 1;
		for(int j = 0; j < i; ++j) r = (r * 10) % i;
		r0 = r;
		len = 0;
		do {
			r = (r * 10) % i;
			len++;
		} while(r != r0);
		if(len > max_len){
			ans = i;
			max_len = len;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d [%d]\n", ans, max_len);
	return 0;
}
