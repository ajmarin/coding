#include <cstdio>

const char h[16] = "hello";
char s[128];
int main(void){
	scanf("%s", s);
	int j = 0;
	for(int i = 0; s[i]; ++i){
		if(s[i] == h[j]) ++j;
	}
	if(j == 5) puts("YES");
	else puts("NO");
	return 0;
}

