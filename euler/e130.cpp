#include <cmath>
#include <cstdio>
#include <ctime>
int getk(int n){
	for(int x = 1, k = 1; ; x = (x * 10 + 1) % n, ++k)
		if(!x) return k;
}
bool prime(int x){
	if(x == 2 || x == 3 || x == 5 || x == 7) return true;
	if(!(x & 1) || !(x % 3)) return false;
	for(int i = 6; ; i += 6){
		int t1 = i - 1, t2 = i + 1;
		if(!(x % t1) || !(x % t2)) return false;
		if(t2 * t2 > x) return true;
	}
}
int main(void){
	clock_t ini = clock();
	int ans = 0;
	for(int i = 1, c = 0; ; i += 2)
		if(i % 5){
			int k = getk(i);
			if(!((i - 1) % k) && !prime(i)){
				ans += i;
				if(++c == 25) break;
			}
		}
	
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
