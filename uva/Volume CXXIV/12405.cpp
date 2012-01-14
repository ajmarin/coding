#include <cstdio>


int main(void){
	scanf("%*d");
	for(int cnum = 0, n; scanf("%d\n", &n) == 1; ){
		int scarecrows = 0;
		char c, p = '#';
		while(n--){
			c = getc( stdin );
			scarecrows += p == '.';
			if(p == '.') c = 'S';
			else if (p == 'S') c = '#';
			p = c;
		}
		printf("Case %d: %d\n", ++cnum, scarecrows + (p == '.'));

	}
	return 0;
}

