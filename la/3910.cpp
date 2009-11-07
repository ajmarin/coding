#include <cctype>
#include <cstdio>

#define IN getc( stdin )

int main(void){
	int k, N, T;
	register char c;
	scanf("%d", &T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d ", &N);
		printf("%d ", ++cnum);
		for(c = IN; !isupper(c); c = IN);
		ungetc(c, stdin);
		for(k = 0, c = IN; isupper(c); c = IN)
			if(++k != N) putc(c, stdout);
		putc(10, stdout);
	}
	return 0;
}

