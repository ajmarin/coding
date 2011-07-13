#include <cstdio>

int c[10];
int main(void){
	for(int n; scanf("%d", &n) == 1; ){
		if(n == 0){ puts("10"); continue; }
		for(int i = 0; i < 10; ++i) c[i] = 0;
		c[1] = (n == 1);
		for(int i = 10; n > 1 && --i > 1; )
			while(!(n % i)) ++c[i], n /= i;
		if(n > 1) puts("-1");
		else {
			for(int i = 0; i < 10; ++i)
				while(c[i] > 0) putc(i + '0', stdout), c[i]--;
			puts("");
		}
	}
	return 0;
}

