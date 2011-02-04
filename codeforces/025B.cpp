#include <cstdio>
int main(void){
	int c = 0, n; scanf("%d\n", &n);
	while(n--){
		putc(getc(stdin), stdout);
		if(++c == 2 && n>1) c = 0, putc('-', stdout);		
	}
	putc(10, stdout);
	return 0;
}
