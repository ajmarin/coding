#include <cstdio>
#include <cctype>

void fastint( register int *n ){
	register char c;
	*n = 0;
	while(!isdigit(c = getc( stdin )));
	do {
		switch( c ){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}while( ( c = getc( stdin ) ));
}
int main(void){
	int ans, a, b, k, n, oa, ob, y;
	for(;;){
		fastint(&a); fastint(&b);
		if(a == 0) break;
		oa = a, ob = b;
		if(b < a) a ^= b ^= a ^= b;
		if(a > 2) ans = (a * b + 1) >> 1;
		else if(a == 2){
			k = a * b, y = k >> 2, n = ((y + 1) >> 1) << 2;
			ans = n + !(y & 1) * (k & 3);
		} else ans = b;
		printf("%d knights may be placed on a %d row %d column board.\n"
				, ans, oa, ob);
	}
	return 0;
}

