#include <cstdio>
#include <cstring>
const char *y = "yes", *n = "no";
int main(void){
	register int i, j, D, N;
	register bool w[100], x;
	while(scanf("%d %d\n",&N,&D) && N){
		memset(w,1,N);
		for(x = i = 0; i < D; i++)
			for(j = 0; j < N; getc(stdin), j++)
				w[j] &= (getc(stdin) - '0');
		for(i = 0; i < N; i++) x |= w[i];
		((x)?(puts(y)):(puts(n)));
	}
	return 0;
}

