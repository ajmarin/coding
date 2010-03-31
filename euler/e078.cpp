#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>

int p[1000000];
int getp(int x){
	if(x < 0) return 0;
	if(p[x]) return p[x];
	int lim = ((int) sqrt(x))+ 1, sum = 0, sign = 1;
	for(int i = 1; i < lim; ++i){
		sum += sign * (getp(x - (i*(3*i-1))/2) + getp(x - (i*(3*i+1))/2));
		sign = -sign;		
	}
	return p[x] = sum % 1000000;
}
int main(void){
	clock_t ini = clock();
	memset(p, 0, sizeof(p));
	p[0] = 1;
	int ans;
	for(ans = 0; getp(ans); ans++);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
