#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>

const int VV= 100001;
struct rads {
	int n, pp;
	bool operator <(const rads k) const {
		return pp < k.pp || (pp == k.pp && n < k.n);
	}
} r[VV];
void reduce(int &x, int d, int &r){
	if(!(x % d)){
		r *= d;
		while(!(x % d)) x /= d;
	}
}
int rad(int k){
	int r = 1;
	reduce(k, 2, r);
	reduce(k, 3, r);
	for(int i = 6; ; i += 6){
		int t1 = i - 1, t2 = i + 1;
		reduce(k, t1, r);
		reduce(k, t2, r);
		if(t2 * t2 > k) break;
	}
	if(k != 1) r *= k;
	return r;
}
int main(void){
	clock_t ini = clock();
	for(int i = 1; i < VV; ++i) r[i].n = i, r[i].pp = rad(i);		
	std::sort(r + 1, r + VV);
	int ans = r[10000].n;
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
