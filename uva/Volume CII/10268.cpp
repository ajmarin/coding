#include <cstdio>
#include <cstdlib>
#include <cstring>

int a[1000000], top;
char c[1048576];

int main(void){
	for(int x; fgets(c, 1048576, stdin); ){
		int ans = top = 0;
		x = atoi(c);
		fgets(c, 1048576, stdin);
		for(char *p = strtok(c, " \t\n"); p != NULL; p = strtok(NULL, " \t\n")) a[top++] = atoi(p);
		for(int i = top--, c = 0; i--; a[i] *= c++);
		for(int i = 0; top--; ++i) ans = ans * x + a[i];
		printf("%d\n", ans);
	}
	return 0;
}

