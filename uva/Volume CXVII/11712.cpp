#include <cstdio>

const char *m = "0 0 0 0 L\n0 1 1 0 R\n1 0 0 0 L\n1 1 2 1 R\n\
2 0 6 0 R\n2 1 3 1 R\n3 1 3 1 R\n3 0 4 1 L\n\
4 1 4 1 L\n4 0 5 1 R\n6 0 2 0 L";
int main(void){
	char v[16];
	for(int n; scanf("%d", &n) && n; ){
		printf("11 %d\n%s\n", n, m);
		for(int i = 0; i < n; ++i){
			scanf("%s", v);
			if(*v == 'A') puts("3 4");
			else if(*v == 'M') puts("1 1");
			else if(*v == 'T') puts("2 2");
			else if(*v == 'W') puts("3 5");
		}
	}
	return 0;
}
