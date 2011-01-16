#include <cstdio>
#include <cmath>
#include <ctime>

int main(void){
	clock_t ini = clock();
	int c, f, lim, t, div = 0;
	for(int i = 4500; div < 500; ++i){
		f = t = (i * (i+1)) >> 1;
		div = c = 0;
		lim = ((int)sqrt(t)) + 1;
		while(!(f & 1)) c++, f >>= 1;
		div = c + 1;		
		for(int k = 3; k < lim; k += 2){
			if(!(f % k)){
				c = 0;
				do {
					c++; f /= k;
				} while(!(f % k));
				div *= (c + 1);
				if(f == 1) break;
			}
		}
		if(f != 1) div <<= 1;
	}
	printf("Time elapsed: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", t);
	return 0;
}
