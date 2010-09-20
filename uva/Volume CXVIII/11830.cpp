#include <cstdio>

char dig[1024];

int main(void){
	int d;
	char c;
	while(scanf("%d", &d) && d){
		scanf("%s", dig);
		int shown = 0;
		for(int i = 0; dig[i]; ++i){
			if(dig[i] - '0' == d) continue;
			if(dig[i] != '0') putc(dig[i], stdout), shown = 1;
			else if(shown) putc('0', stdout);
		}
		if(!shown) puts("0");
		else putc(10, stdout);
	}
	return 0;
}

