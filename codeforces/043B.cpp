#include <cstdio>
#define IN				getc(stdin)
#define READL(x)		for(char c = IN; c != EOF && c != 10; c = IN)
int cnt[128];
int main(void){
	bool yes = true;
	for(int i = 0; i < 128; ++i) cnt[i] = 0;
	READL(c) ++cnt[c];
	READL(c) yes &= c == 32 || cnt[c]--;
	puts(yes ? "YES":"NO");
	return 0;
}
