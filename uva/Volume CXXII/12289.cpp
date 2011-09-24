#include <cstdio>

const char *w[3] = {"one", "two", "three"};
int main(void){
	char wrote[16];
	int i, T;
	for(scanf("%d", &T); T--; ){
		int errors[3] = {0, 0, 0};
		scanf("%s", wrote);
		for(i = 0; i < 3; ++i){
			errors[0] += wrote[i] != w[0][i];
			errors[1] += wrote[i] != w[1][i];
			errors[2] += wrote[i] != w[2][i];
		}
		for(i = 0; i < 3; ++i)
			if(errors[i] <= 1) printf("%d\n", i + 1);
	}
	return 0;
}

