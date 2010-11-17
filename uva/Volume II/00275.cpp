#include <cstdio>

int pos[4096];
char z[4096];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int n, d; scanf("%d %d", &n, &d) == 2 && (n || d); ){
		int p = 1; z[0] = '.';
		for(int i = 0; i < d; ++i) pos[i] = -1;
		n = (n % d) * 10;
		while(1){
			z[p] = n / d + '0';
			n = (n % d);
			if(pos[n] != -1) break;
			pos[n] = p++;
			n *= 10;
		}
		z[p + (n && z[p] != z[pos[n]])] = 0;
		for(int i = 0; z[i]; ++i){
			if(i && !(i % 50)) putc(10, stdout);
			putc(z[i], stdout);
		}
		putc(10, stdout);
		if(n == 0) printf("This expansion terminates.\n");
		else printf("The last %d digits repeat forever.\n", p - pos[n]);
		putc(10, stdout);
	}
	return 0;
}

