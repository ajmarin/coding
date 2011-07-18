#include <cstdio>

int main(void){
	for(int n; scanf("%d", &n) && n; ){
		int a = 0, b = 0;
		for(int i = 0; i < 32; ++i)
			if(n & (1<<i)){
				if(a > b) b |= (1 << i);
				else a |= (1 << i);
			}
		printf("%d %d\n", a, b);
	}
	return 0;
}

