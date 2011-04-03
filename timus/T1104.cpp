#include <cstdio>
char n[1000048];
int max(int a, int b){ return a > b ? a : b; }
int value(char c){
	if(c >= '0' && c <= '9') return c - '0';
	return c - 'A' + 10;
}
int main(void){
	while(scanf("%s", n) == 1){
		int base, i, minb = 2, mod;
		for(i = 0; n[i]; ++i) minb = max(minb, value(n[i])+1);
		for(base = minb; base < 37; ++base){
			for(i = mod = 0; n[i]; ++i) mod = (mod * base + value(n[i])) % (base - 1);
			if(!mod) {
				printf("%d\n", base); 
				break;
			}
		}
		if(base == 37) puts("No solution.");
	}
	return 0;
}

