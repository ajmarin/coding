#include <cstdio>

int main(void){
	for(int N, L, C; scanf("%d %d %d", &N, &L, &C) == 3; ){
		int c = 0;
		int l = 1, p = 1, z;
		for(int i = 0; i < N; ++i){
			scanf(" ");
			scanf("%*s%n", &z);
			if(c + z > C){ 
				c = 0; 
				if(++l > L) l = 1, ++p;
			}
			c += z + 1;
		}
		printf("%d\n", p);
	}
	return 0;
}

