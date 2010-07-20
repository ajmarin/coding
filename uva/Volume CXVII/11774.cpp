#include <cctype>
#include <cstdio>
#define MAX 1048576
char buf[MAX], *lim = buf + MAX, *now = lim;
void readint(int *n){	
	while(now != lim && !isdigit(*now)) now++;
	if(now == lim){
		int r = fread(buf, 1, MAX - 1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		while(isdigit(*lim)) ungetc(*lim--, stdin);
		now = buf;
	}
	while(!isdigit(*now)) now++;
	*n = 0;	
	while(isdigit(*now)) *n = *n * 10 + *now++ - '0';
}
int gcd(int a, int b){
	if(!b) return a;
	return gcd(b, a % b);
}
int main(void){
	int a, b, t;
	readint(&t);
	for(int cnum = 0; cnum++ < t; ){
		readint(&a); readint(&b);
		printf("Case %d: %d\n", cnum, (a + b)/gcd(a, b));
	}
	return 0;
}
