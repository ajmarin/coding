#include <cstdio>

int main(void){
	int mod;
	for(char c = 0; ; c = 0){
		while(c != EOF && c != '0' && c != '1') c = getc(stdin); 
		if(c == EOF) break;
		for(mod = 0; c != '#'; c = getc(stdin)) 
			mod = ((mod << 1) | (c == '1')) % 131071;
		puts(mod ? "NO" : "YES");
	}
	return 0;
}

