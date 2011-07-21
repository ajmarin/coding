#include <cstdio>

const int MAXL = 100048;
unsigned char m[128];
char prog[MAXL];
int main(void){
	int t; scanf("%d\n", &t);
	for(int cnum = 0; cnum++ < t; ){
		int p = 0;
		for(int i = 0; i < 100; ++i) m[i] = 0;
		scanf("%[.-+><]\n", prog);
		for(char *c = prog; *c; ++c){
			if(*c == '-') --m[p];
			else if(*c == '+') ++m[p];
			else if(*c == '<') --p;
			else if(*c == '>') ++p;
			if(p == - 1) p = 99;
			else if(p == 100) p = 0;
		}
		printf("Case %d:", cnum);
		for(int i = 0; i < 100; ++i)
			printf(" %02X", m[i]);
		puts("");
	}
	return 0;
}

