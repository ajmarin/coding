#include <cmath>
#include <cstdio>
#include <ctime>

char v[350];
void multi(int q) { 
    int c = 0, i; 
	for(i = 0; v[i]; ++i){
		c = ( (v[i] - '0') * q + c );
		v[i] = '0' + c % 10;
		c /= 10;
    } 
    while(c) { v[i++]='0'+(c%10); c /= 10; }
	v[i] = 0;
} 
int main(void){
	clock_t ini = clock();
	int ans = 0;
	v[0] = '1'; v[1] = 0;
	for(int i = 2; i < 101; ++i) multi(i);
	for(int i = 0; v[i]; ++i) ans = ans + v[i] - '0';
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

