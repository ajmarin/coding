#include <cstdio>

int main(void){
	int i, k, t; scanf("%d", &t);
	for(int c = 0; c++ < t; ){
		scanf("%d\n", &k); i = 0;
		printf("%d ", c);
		for(char c; (c = getc(stdin)) != 10 && c != EOF; )
			if(++i != k) putc(c, stdout);
		putc(10, stdout);
	}
	return 0;
}
