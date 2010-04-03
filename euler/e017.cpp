#include <cmath>
#include <cstdio>
#include <ctime>

int u[10] = { 0, 3, 3, 5, 4, 4, 3, 5, 5, 4 };
int s[10] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
int d[10] = { 0, 0, 6, 6, 5, 5, 5, 7, 6, 6 };
int ans = 0;
void represent(int k){
	int digit;
	if(k > 999){
		digit = k / 1000;
		ans += u[digit] + 8;
		k = k - 1000 * digit;
		if(k) ans += 3;
	}
	if(k > 99){
		digit = k / 100;
		ans += u[digit] + 7;
		k = k - 100 * digit;
		if(k) ans += 3;
	}
	if(k > 9 && k < 20) ans += s[k - 10];
	else ans += d[k / 10] + u[k % 10];
}
int main(void){
	clock_t ini = clock();
	for(int i = 1; i < 1001; ++i) represent(i);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

