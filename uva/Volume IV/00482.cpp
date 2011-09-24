#include <cstdio>
#include <cstdlib>
#include <cstring>

int p[1048576];
char line[1048576], *v[1048576];

int main(void){
	int T; scanf("%d", &T);
	for(char c = getchar(); c != 10; c = getchar());
	for(int c = 0; c < T; ++c){
		int i = 0;
		char *ptr;
		gets(line);
		gets(line);
		if(c) puts("");
		for(ptr = strtok(line, " "), i = 0; ptr != NULL; ptr = strtok(NULL, " "))
			p[i++] = atoi(ptr) - 1;
		gets(line);
		for(ptr = strtok(line, " "), i = 0; ptr != NULL; ptr = strtok(NULL, " "))
			v[p[i++]] = ptr;
		for(int j = 0; j < i; ++j) printf("%s\n", v[j]);
	}
	return 0;
}

