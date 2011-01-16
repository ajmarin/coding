#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

char n[100][50];
int main(void){
	clock_t ini = clock();
	for(int i = 0; i < 100; ++i){
		scanf("%s", n[i]);
		reverse(n[i], n[i] + 50);
	}
	int s = 0, lim = 10;
	for(int i = 0; i < 50; ++i){
		for(int j = 0; j < 100; ++j)
			s = s + n[j][i] - '0';
		n[0][i] = s % 10 + '0';
		s = s / 10;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d", s);
	while(s) s /= 10, --lim;
	for(int i = 0; i < lim; ++i) printf("%c", n[0][49 - i]);
	putc(10, stdout);
	return 0;
}
