#include <cstdio>
int main(void){
	int add = 0, pv, v = 0;
	int n, d; scanf("%d %d", &n, &d);
	for(int i = 0; i < n; ++i){
		pv = v;
		scanf("%d", &v);
		if(v <= pv){
			int c = (pv - v) / d + 1;
			v += c * d;
			add += c;
		}
	}
	printf("%d\n", add);
	return 0;
}
