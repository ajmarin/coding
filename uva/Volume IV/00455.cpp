#include <cstdio>
#include <cstring>

char word[128];
int len;

bool period(int x){
	if(len % x) return false;
	for(int i = 1; i < len / x; ++i)
		if(strncmp(word, word + x * i, x)) return false;
	return true;
}
int main(void){
	int p, t; scanf("%d\n", &t);
	while(t-- && gets(word)){
		for(len = 0; word[len]; ++len);
		for(p = 1; !period(p); ++p);
		printf("%d\n", p);
		if(t) puts("");
		gets(word);
	}
	return 0;
}

