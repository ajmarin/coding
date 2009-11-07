#include <cctype>
#include <cstdio>

char s[1024];

int main(void){
	bool hasund, hasupp;
	bool prev;
	register char *p;
	while(fgets(s, 1024, stdin)){
		hasund = hasupp = prev = 0;
		for(p = s; *p != 10; ++p){
			if(p != s && *p == *(p-1) && *p == '_')
				hasund = hasupp = 1;
			hasund |= (*p == '_');
			hasupp |= isupper(*p);
		}
		*p-- = 0;
		if(*s == '_' || isupper(*s) || *p == '_' || (hasund && hasupp)){
			puts("Error!");
			continue;
		}
		if(hasund){
			for(p = s; *p; ++p){
				if(*p == '_'){
					prev = 1;
					continue;
				}
				if(prev && isalpha(*p)) putc(toupper(*p), stdout);
				else putc(*p, stdout);
				prev = 0;
			}
			putc(10, stdout);
		} else if(hasupp){
			for(p = s; *p; ++p){
				if(isupper(*p)){
					putc('_', stdout);
					putc(tolower(*p), stdout);
				} else putc(*p, stdout);
			}
			putc(10, stdout);
		} else puts(s);
	}
	return 0;
}

