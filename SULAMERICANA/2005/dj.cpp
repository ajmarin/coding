#include <cstdio>
#define LIM 100000001
char m[30][128];
int w[30];
int main(void){
	int cq, i, j, need, p, seg, N, Q;
	w[0] = 0;
	while(scanf("%d%d",&N,&Q) && (N||Q)){
		for(i = 0; i < N; i++) scanf("%s",m[i]);
		if(i != 1){
			for(i = 1, p = N; w[i-1] < LIM; i++,p*=N)
				w[i] = (i*p)+w[i-1];
			for(i = 0; i < Q; i++){
				scanf("%d",&cq);
				for(j = 1; w[j] < cq; j++);
				cq -= w[j-1];
				seg = (cq+j-1)/j - 1;
				need = ((cq%j)? j - cq%j: 0);
				for(j = 0; j < need; j++) seg/=N;
				puts(m[seg%N]);
			}
		} else 
			for(i = 0; i < Q; scanf("%d",&cq), i++) puts(m[0]);
		putc('\n',stdout);
	}
	return 0;
}
