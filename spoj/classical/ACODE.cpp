#include <cstdio>

long long w[5005];
int main(void){
	for(char c, p; (c = getc(stdin) - '0') > 0; ){
		w[0] = w[1] = 1;
		int i;
		for(i = 1, p = c; (c = getc(stdin) - '0') > -1; p = c, ++i)
			w[i + 1] = (c ? w[i] : 0) + (p && 10*p+c < 27 ? w[i - 1]: 0);
		printf("%lld\n", w[i]);
		c += '0';
		while(c!=10) c = getc(stdin);
	}
	return 0;
}

