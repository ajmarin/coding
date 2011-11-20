#include <cstdio>

char s1[128], s2[128];
int main(void){
	int pow, t; scanf("%d\n", &t);
	for(int cnum = 0; cnum++ < t; ){
		long long c = 1;
		while(getc(stdin) != '(');
		scanf("%[a-z]+%[a-z])^%d", s1, s2, &pow);
		printf("Case %d: ", cnum);
		for(int i = 0; i <= pow; ++i){
			if(i) putc('+', stdout);
			if(c != 1) printf("%lld*", c);
			if(pow - i) printf("%s", s1);
			if(pow - i > 1) printf("^%d", pow - i);
			if(pow - i && i) putc('*', stdout);
			if(i) printf("%s", s2);
			if(i > 1) printf("^%d", i);
			c = (c * (pow - i)) / (i + 1);
		}
		puts("");
	}
	return 0;
}

