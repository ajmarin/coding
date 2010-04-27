#include <cstdio>
#include <cmath>

char word[10005];
int main(void){
	int l, t;
	scanf("%d\n", &t);
	while(t--){
		fgets(word, 10005, stdin);
		l = -1;
		for(char *p = word; *p; ++p, ++l);
		int root = floor(sqrt(l));
		if(root * root != l) puts("INVALID");
		else {
			for(int c = 0; c < root; ++c)
				for(int k = c; k < l; k += root)
					putc(word[k], stdout);
			putc(10, stdout);
		}
	}
	return 0;
}

