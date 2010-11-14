#include <cstdio>

const char *ans[2] = {"wrong", "right"};
int sqr(int x){ return x * x; }
int main(void){
	int a, b, c;
	bool r;
	while(scanf("%d %d %d", &a, &b, &c) == 3 && (a || b || c)){
		if(c > b && c > a) r = sqr(a) + sqr(b) == sqr(c);
		if(b > c && b > a) r = sqr(a) + sqr(c) == sqr(b);
		if(a > b && a > c) r = sqr(b) + sqr(c) == sqr(a);
		puts(ans[r]);
	}
	return 0;
}

