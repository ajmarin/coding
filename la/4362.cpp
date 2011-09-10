#include <cstring>
#include <cstdio>

#define FOR(i, n)	for(int i = 0; i < n; ++i)
const char *map[10] = {"063", "010", "093", "079", "106", "103", "119",
	"011", "127", "107"};

char line[1024];

int readLine(char *s){
	int read = 1;
	char c = getc(stdin);
	if(c == 10 || c == EOF) return -(c == EOF);
	for(*s++ = c; (c = getc(stdin)) != 10; *s++ = c, ++read);
	*s = 0;
	return read;
}
int main(void){
	while(readLine(line) > 0 && strcmp(line, "BYE")){
		int a(0), b(0), i, s[15], top = 0;
		printf("%s", line);
		for(i = 0; line[i] != '+'; i += 3)
			FOR(z, 10) if(!strncmp(line + i, map[z], 3)) a = 10*a + z;
		for(++i; line[i] != '='; i += 3)
			FOR(z, 10) if(!strncmp(line + i, map[z], 3)) b = 10*b + z;
		for(int res = a + b; res; s[top++] = res % 10, res /= 10);
		while(top--) printf("%s", map[s[top]]);
		puts("");
	}
	return 0;
}

