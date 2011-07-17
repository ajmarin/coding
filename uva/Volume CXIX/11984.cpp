#include <cstdio>

int main(void){
	int cnum = 0, t; scanf("%d", &t);
	for(int c, inc; t-- && scanf("%d %d", &c, &inc) == 2; )
		printf("Case %d: %.2lf\n", ++cnum, c + inc / 1.8);
	return 0;
}

