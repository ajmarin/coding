#include <cmath>
#include <cstdio>
#include <set>
using namespace std;
int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
		31, 37, 41, 43, 47, 53, 59, 61};
bool prime[65];
typedef unsigned long long ull;
set < ull > s;
double lim2 = 64 * log(2);
int lim = 1000;
int main(void){
	for(int i = 0; i < 65; ++i) prime[i] = 0;
	for(int i = 0; i < 18; ++i) prime[p[i]] = 1;
	for(int i = 2; lim > 3; ++i){
		ull b = i, v = i;
		lim = ceil(lim2 / log(i));
		
		//printf("limite para %d = %d\n", i, lim);
		for(int e = 2; e < lim; ++e){
			v *= b;
			if(!prime[e]) s.insert(v);
		}
	}
	puts("1");
	for(typeof(s.begin()) it = s.begin(); it != s.end(); it++)
		printf("%llu\n", *it);
	return 0;
}
	