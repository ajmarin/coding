#include <cstdio>
bool ap(int x){
	int div = !(x & 1);
	while(!(x&1)) x >>= 1;
	for(int i = 3; x != 1; i += 2){
		div += !(x % i);
		while(!(x%i)) x /= i;
		if(i * i > x) break;
	}
	div += x != 1;
	return div == 2;
}
int main(void){
	int ans = 0, n; scanf("%d", &n);
	for(int i = 6; i <= n; ++i) ans += ap(i);
	printf("%d\n", ans);
	return 0;
}

