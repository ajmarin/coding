#include <cstdio>

char s[128];
int main(void){
	int d, n, t = 0; scanf("%d", &n);
	if(n == 0) puts("0");
	else {
		while(n){
			s[t++] = '0' + (n & 1);
			n = (n - (n < 0)) / -2;
		}
		while(t--) putc(s[t], stdout);
		putc(10, stdout);
	}
	return 0;
}

