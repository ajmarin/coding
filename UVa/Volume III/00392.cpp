/////////////////////////////////
// 00392 - Polynomial Showdown
/////////////////////////////////
#include<cstdio>
#include<cctype>
char sign;
int n, i;
bool first;
void readn( register int *n ){
	sign = '+';
	register char c,prev;
	*n = 0;
	while( !isdigit( c = getc(stdin) ) ) prev = c;
	if(prev == '-') sign = '-';
	do {
		switch(c) {			
			case ' ' : case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	} while(( c = getc(stdin) ) != '\n' );
}
void doprint(int degree){
	if(!first) printf(" %c ",sign);
	else if(sign == '-') printf("%c",sign);
	if(degree > 1){
		if(n!=1) printf("%dx^%d",n,degree);
		else printf("x^%d",degree);
	} else if (degree){
		if(n!=1) printf("%dx",n);
		else printf("x");
	} else printf("%d",n);
	first = false;
}
int main(void){
	while(scanf("%d",&n)!=EOF){
		first = 1, sign = '+';
		if(n<0) sign = '-',n/=-1;
		if(n) doprint(8);
		for(i = 0; i < 8; i++){
			readn(&n);
			if(n) doprint(7-i);
		}
		if(first) putchar('0');
		putchar('\n');
	}
	return 0;
}

