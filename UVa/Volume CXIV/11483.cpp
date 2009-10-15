#include <cstdio>

char line[2048], ans[2048];
int main(void){
	int N, cnum = 0;
	while(scanf("%d",&N) && N){
		printf("Case %d:\n", ++cnum);
		puts("#include<string.h>\n#include<stdio.h>\nint main()\n{");
		while(N--){
			fgets(line, 2048, stdin);
			if(line[0] == 10){ N++; continue;}
			register char *p, *o = ans;
			fputs("printf(\"",stdout);
			for(p = line; *p != 10; p++){
				if(*p == '\\' || *p == '\"') *o++ = '\\';
				*o++ = *p;
			}
			*o++ = '\\'; *o++ = 'n'; *o++ = '\"'; *o++ = ')';
			*o++ = ';'; *o = 0;
			puts(ans);
		}
		puts("printf(\"\\n\");\nreturn 0;\n}");
	}
	return 0;
}
		
