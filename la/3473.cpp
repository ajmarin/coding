#include <cstdio>

int R[2][1000];
void fastint( register int *n ){
	register char c;
	*n = 0;
	while( ( c = getc( stdin ) )){
		switch( c ){
			case ' ': case '\n': return ;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}
}
int main(void){
	int i, j, N, Q, TQ, TR;
	fastint(&N);
	for(int cnum = 1; N; cnum++){
		fastint(&TR);
		for(i = 0; i < TR; i++)
			fastint(&R[0][i]),
			fastint(&R[1][i]);
		fastint(&TQ);
		printf("Genome %d\n",cnum);
		for(i = 0; i < TQ; i++){
			fastint(&Q);
			for(j = 0; j < TR; j++)
				if(Q >= R[0][j] && Q <= R[1][j])
					Q = R[1][j]+R[0][j]-Q;
			printf("%d\n",Q);
		}
		fastint(&N);
	}
	return 0;
}

