#include <cstdio>

int main(void){
	int z; scanf("%d", &z);
	for(int c; scanf("%d", &c) == 1; ){
		int f, n, s, t;
		f = s = t = -1;
		for(int i = 0; i < 10; ++i){
			scanf("%d", &n);
			if(n >= f) t = s, s = f, f = n;
			else if(n >= s) t = s, s = n;
			else if(n >= t) t = n;
		}
		printf("%d %d\n", c, t);
	}
	return 0;
}

