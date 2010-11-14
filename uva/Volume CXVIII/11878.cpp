#include <cstdio>

int main(void){
	int ans = 0; char op, x;
	int a, b, c;
	while(scanf("%d%c%d=", &a, &op, &b) == 3){
		x = getc(stdin);
		if(x == '?') continue;
		ungetc(x, stdin);
		scanf("%d", &c);
		if(op == '-' && a - b == c) ans++;
		if(op == '+' && a + b == c) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
