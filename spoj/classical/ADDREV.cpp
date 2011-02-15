#include <cstdio>

template <class _T> _T reverse(_T a){
	for(_T r = 0; ; a /= 10)
		if(a) r = r * 10 + (a % 10);
		else return r;
}
int main(void){
	int a, b, t; scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}
	return 0;
}
