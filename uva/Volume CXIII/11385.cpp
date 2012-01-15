#include <cstdio>
#include <cstring>

int fib[128], list[256];
char text[256], output[256];

int main(void){
	int i, j;
	char c;
	fib[0] = fib[1] = 1;
	for(int i = 2; i < 128; ++i) fib[i] = fib[i-1] + fib[i-2];
	scanf("%*d");
	for(int n; scanf("%d", &n) == 1; ){
		memset(output, 32, sizeof output);

		for(i = 0; i < n; ++i) scanf("%d", list + i);
		scanf("\n");
		c = getc(stdin);
		for(i = 0; c != 10; c = getc(stdin)) 
			if(c >= 'A' && c <= 'Z') text[i++] = c;

		int hi = -1;
		for(i = 0; i < n; ++i){
			for(j = 1; list[i] != fib[j]; ++j);
			--j;
			output[j] = text[i];
			if(j > hi) hi = j;
		}
		output[hi+1] = 0;
		puts(output);
	}
	return 0;
}

