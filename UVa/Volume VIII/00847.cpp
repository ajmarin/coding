#include <cstdio>
const char *w[2] = {"Stan wins.","Ollie wins."};
unsigned int a, div[2] = {2,9};
int main(void){
	for(bool x; scanf("%u",&a)!=EOF; puts(w[x]))
		for(x = 1; a > 1; x=!x)
			a = (a+div[x]-1)/div[x];
	return 0;
}

