#include <cctype>
#include <cstdio>
#include <cstring>

int main(void){
	for(char isbn[128], line[128]; gets(line); ){
		int cnt = 0, s1 = 0, s2 = 0;
		bool valid = true;
		char *p;
		for(p = line; isspace(*p); ++p);
		strcpy(isbn, p);
		for(p = isbn; *p; ++p);
		for(--p; isspace(*p); --p);
		*(p + 1) = 0;
		for(p = isbn; *p; ++p)
			if(*p >= '0' && *p <= '9') s2 += s1 += *p - '0', ++cnt;
			else if(*p == 'X' && cnt == 9) s2 += s1 += 10, ++cnt;
			else valid &= *p == '-';
		while(*(p-1) == ' ') --p;
		*p = 0;
		valid &= cnt == 10;
		valid &= s2 % 11 == 0;
		printf("%s is %s.\n", isbn, "incorrect" + (valid << 1));
	}
	return 0;
}

