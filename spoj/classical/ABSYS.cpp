#include <cstdio>
#include <cstring>

char s[1024];
int main(void){
	int t; scanf("%d\n", &t);
	while(t--){
		while(fgets(s, 1024, stdin) && strlen(s) < 3);
		int a, b, c, it = 0;
		for(char *p = s; *p != 'm'; ++p) if(*p == '+' || *p == '=') it++;
		if(it == 0){
			sscanf(s, "%*s + %d = %d", &b, &c);
			a = c - b;
		} else if(it == 1){
			sscanf(s, "%d + %*s = %d", &a, &c);
			b = c - a;
		} else {
			sscanf(s, "%d + %d = %*s", &a, &b);
			c = a + b;
		}
		printf("%d + %d = %d\n", a, b, c);
	}
	return 0;
}

