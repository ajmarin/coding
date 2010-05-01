#include <cstdio>

int m[1001] = {0};
int d(int k){
	int a = k, r = 1, v;
	for(int x = 2; ; ++x){
		if(x * x > k) break;
		if(!(k % x)){
			v = 1;
			while(!(k % x)){
				v = v * x + 1;
				k /= x;
			}
			r *= v;
		}
	}
	if(k > 1) r *= (1 + k);
	return r;
}
int main(void){
	for(int i = 1; i < 1000; ++i) {
		int k = d(i);
		if(k < 1001) m[k] = i;
	}
	for(int cnum = 1, k; scanf("%d", &k) && k; ++cnum)
		if(m[k]) printf("Case %d: %d\n", cnum, m[k]);
		else printf("Case %d: -1\n", cnum);
	return 0;
}