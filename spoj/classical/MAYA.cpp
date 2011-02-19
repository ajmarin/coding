#include <cstdio>

int main(void){
	int v[7] = {1, 20, 360};
	char line[1024];
	for(int i = 3; i < 7; ++i) v[i] = 20 * v[i - 1];
	for(int n, r, z; scanf("%d\n", &n) == 1 && n; ){
		r = 0;
		while(n--){
			fgets(line, 1024, stdin);
			z = 0;
			for(char *p = line; *p; ++p){
				if(*p == '.') ++z;
				else if(*p == '-') z += 5;
			}
			r += z * v[n];
		}
		printf("%d\n", r);
	}
	return 0;
}

