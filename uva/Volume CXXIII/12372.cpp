#include <cstdio>

#define GOOD(a,b,c) (a < 21 && b < 21 && c < 21)
const char *ans[2] = {"bad", "good"};

int main(void){
	scanf("%*d");
	for(int a, b, c, z = 0; scanf("%d%d%d", &a, &b, &c) == 3; )
		printf("Case %d: %s\n", ++z, ans[GOOD(a,b,c)]);
	return 0;
}

