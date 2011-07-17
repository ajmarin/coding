#include <cstdio>

int a, b, c;
int f(int x){
	return (a * x + b) * x + c;
}

int main(void){
	for(int d, L; scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) == 5; ){
		int ans = 0;
		if(!(a || b || c || d || L)) break;
		for(int i = 0; i <= L; ++i)
			ans += !(f(i) % d);
		printf("%d\n", ans);
	}
	return 0;
}

