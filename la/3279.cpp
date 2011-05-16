#include <cstdio>

int c[2];
char name1[32], name2[32], x[32];

int main(void){
	while(scanf("%s %s %s", name1, name2, x)){
		if(name1[0] == '#') break;
		int n, z; scanf("%d", &n);
		c[0] = c[1] = 0;
		while(n--){
			scanf("%d", &z);
			++c[z & 1];
		}
		printf("%s %d %s %d\n", name1, c[1 - (x[0]=='o')], name2, c[x[0]=='o']);
	}
	return 0;
}

