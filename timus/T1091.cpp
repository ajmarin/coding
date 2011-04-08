#include <cstdio>
int fc[51] = 
	{0, 0, 1, 1, 2, 1, 2, 1, 3, 2,
	 2, 1, 3, 1, 2, 2, 4, 1, 3, 1,
	 3, 2, 2, 1, 4, 2, 2, 3, 3, 1,
	 3, 1, 5, 2, 2, 2, 4, 1, 2, 2,
	 4, 1, 3, 1, 3, 3, 2, 1, 5, 2, 3};
int c(int n, int k){
	if(n < k) return 0;
	if(k > n - k) k = n - k;
	int r = 1, m = n, d = 1;
	for(int i = 0; i < k; ++i) r *= m--, r /= d++;
	return r;
}
bool sqfree(int x){
	for(int i = 2; i * i <= x; ++i)
		if(!(x % (i * i))) return false;
	return true;
}
int main(void){
	for(int k, s; scanf("%d %d", &k, &s) == 2; ){
		int r = 0;
		for(int i = 2; i < s; ++i){
			if(!sqfree(i)) continue;
			if(fc[i] & 1) r += c(s / i, k);
			else r -= c(s / i, k);
		}
		printf("%d\n", r > 10000 ? 10000 : r);
	}
	return 0;
}

