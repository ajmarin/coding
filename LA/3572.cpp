#include <cstdio>

int main(void){
	int T, N;
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		int q = (1 + (N<<1))/3;
		printf("%d %d %d\n",++cnum,N,q);
		int st = N - q + 1, y = 1;
		if(N < 4){
			if(N < 3) printf("[1,1]\n");
			else printf("[1,1] [3,2]\n");
		} else {
			for(int i = 0; i < q; ++i){
				printf("[%d,%d]",st++,y);
				if(i%8 == 7) putc(10, stdout);
				else putc(' ', stdout);
				y += 2;
				if(y > st) y = 2;
			}
			if(q%8) putc(10, stdout);
		}
		if(cnum < T) putc(10, stdout);
	}
	return 0;
}

