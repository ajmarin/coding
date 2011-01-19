#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
using namespace std;
typedef unsigned long long int LLU;
LLU ans = 0;
int p[10];
bool perm(){
	int k, l;
	for(k = 8; k > 0 && p[k] >= p[k + 1]; --k);
	if(!k) return 0;
	for(l = 9; p[k] >= p[l]; --l);
	swap(p[k], p[l]);
	for(int i = k + 1, j = 9; i < j; ++i, --j) swap(p[i], p[j]);
	return 1;
}
LLU value(){
	LLU r = 0;
	for(int i = 0; i < 10; ++i) r = r * 10 + p[i];
	return r;
}
bool prime(LLU x){
	if(x <= 1) return 0;
	if(x == 2 || x == 3 || x == 5 || x == 7) return 1;
	if(!(x & 1) || !(x % 3)) return 0;
	for(int z = 6; ; z += 6){
		LLU t1 = z - 1, t2 = z + 1;
		if(!(x % t1) || !(x % t2)) return 0;
		if(t2 * t2 > x) return 1;
	}
}
void fill(int k, int d, int m){
	if(k == 10){
		sort(p + 1, p + 10);
		for(LLU x = value(); perm(); x = value()) if(prime(x)) ans += x;		
		return;
	}
	for(int i = m; i < 10; ++i)
		if(i != d){
			p[k] = i;
			fill(k + 1, d, i);
		}
}
int main(void){
	clock_t ini = clock();
	for(int f = 1; f < 10; ++f){ // First digit
		p[0] = f;
		printf("f = %d\n", f);
		for(int r = 2; r < 10; ++r) // Repeat count			
			for(int d = 0; d < 10; ++d){ // What number will repeat
				printf("\tr = %d [%d]\n", r, d);
				for(int x = 1; x <= r; ++x) p[x] = d;
				fill(r + 1, d, 0);
			}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %lld\n", ans);
	return 0;
}
