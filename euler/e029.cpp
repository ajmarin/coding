#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

bool unique[101];
void count_new_powers(int a, int *power){
	bool rep = 1;
	int mult, n = a, omult = -1;
	for(int i = 2; ; ++i){
		mult = 0;
		if(i * i > a) break;
		if(!(a % i)){
			mult = 0;
			do { a /= i; ++mult; } while(!(a % i));
			if(omult == -1) omult = mult;
			else rep &= mult == omult;
		}
	}
	if(rep & a == 1) *power = omult;
}
int main(void){
	clock_t ini = clock();
	int ans = 0, power;
	for(int a = 2; a < 101; ++a){
		power = 0;
		count_new_powers(a, &power);
		if(power){
			memset(unique, 1, sizeof(unique));
			for(int b = 1; b < power; ++b)
				for(int c = 2; c < 101; ++c){
					int d = b * c;
					if(!(d % power)) unique[d / power] = 0;
				}
			for(int b = 2; b < 101; ++b) ans += unique[b];
		} else ans += 99;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

