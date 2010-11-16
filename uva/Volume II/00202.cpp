#include <cstdio>

int pos[4096];
char z[4096];
int min(int a, int b){ return a < b ? a : b; }
int main(void){
	for(int n, d; scanf("%d %d", &n, &d) == 2; ){
		int l, r, p = 0; z[0] = 0;
		printf("%d/%d = %d.", n, d, n / d);
		for(int i = 0; i < d; ++i) pos[i] = -1;
		n = (n % d) * 10;
		while(1){
			z[p] = n / d + '0';
			n = (n % d);
			if(pos[n] != -1) break;
			pos[n] = p++;
			n *= 10;
		}
		int s = p - pos[n];
		l = pos[n] + (z[p] != z[pos[n]]); 
		r = l + min(50, s);
		for(int i = 0; i < l; ++i) putc(z[i], stdout);
		putc('(', stdout);
		for(int i = l; i < r; ++i) putc(z[i], stdout);
		if(s >= 50) printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", s);
	}
	return 0;
}

