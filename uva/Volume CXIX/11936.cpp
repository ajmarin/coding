#include <cstdio>

int main(void){
	int t; scanf("%d", &t);
	for(int a, b, c; t-- && scanf("%d %d %d", &a, &b, &c) == 3; )
		puts(a+b <= c || a+c <= b || b+c <= a ? "Wrong!!" : "OK");
	return 0;
}

