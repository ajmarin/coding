#include <cstdio>

char n[128];
int main(void){
	while(scanf("%s", n + 1) == 1){
		int c = 0, i, len = 0; while(n[++len]);
		for(i = len; n[--i] == '0'; n[i] = '9');
		if(len == 2 && n[1] == '1'){ puts("1"); continue; }
		--n[i];
		for(i = len; --i; ) n[i] = '0' + (c = c + (n[i] - '0') * 2) % 10, c /= 10;
		if(c){
			n[0] = c + '0';
			puts(n);
		} else puts(n+1);
	}
	return 0;
}

