#include <cstdio>
#include <cstdlib>
#define LIM 2147483647
char a[2048], b[2048];
int main(void){
	long double n1, n2;
	char op;
	while(scanf("%s %c %s", a, &op, &b) == 3){
		n1 = atof(a); n2 = atof(b);
		printf("%s %c %s\n", a, op, b);
		if(n1 > LIM) puts("first number too big");
		if(n2 > LIM) puts("second number too big");
		if(op == '+') n1 += n2; else n1 *= n2;
		if(n1 > LIM) puts("result too big");
	}
	return 0;
}

