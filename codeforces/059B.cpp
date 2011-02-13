#include <cstdio>
int main(void){	
	int m = 128, n, s = 0, t; scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		s += t;
		if(t & 1 && t < m) m = t;
	}
	if(!(s & 1)) s -= m & 1 ? m : s;
	printf("%d\n", s);
	return 0;
}
