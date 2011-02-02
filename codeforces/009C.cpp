#include <cctype>
#include <cstdio>
int main(void){
	char c, p = '0';
	int x = 0;
	for(c = getc(stdin); isdigit(c); p = c > p ? c : p, c = getc(stdin))
		x = (x << 1) + (c > '0' || p > '1');
	printf("%d\n", x);
	return 0;
}

