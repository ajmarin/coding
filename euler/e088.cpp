#include <cmath>
#include <cstdio>
#include <ctime>
#include <set>
using namespace std;
const int MAX = 12001;
int small[MAX];
bool seen[MAX<<1];
void bt(int p, int s, int d, int minp){
	int L = (MAX << 1) / p;
	int k;
	if(d){
		k = p - s + d;
		if(k > -1 && k < MAX) small[k] = min(small[k], p);
	}
	for(int i = minp; i < L; ++i) bt(p * i, s + i, d + 1, i);
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 0; i < MAX; ++i) small[i] = 1 << 29;
	for(int i = 0; i < MAX << 1; ++i) seen[i] = 0;
	bt(1, 0, 0, 2);
	for(int k = 2; k < MAX; ++k){
		int v = small[k];
		if(!seen[v]){
			ans += v;
			seen[v] = 1;
		}
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
