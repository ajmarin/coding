#include <cstdio>
#define max(a,b) ((a<b)?(b):(a))
void fastint( register int *n ){
	register char c;
	*n = 0;
	while( ( c = getc( stdin ) )){
		switch( c ){
			case ' ': case '\n': return;
			default: (*n) *= 10; (*n) += ( c - '0' ); break;
		}
	}
}
int main(void){
	int c, i, j, pC1, pC2, pL1, pL2, r, temp, v;
	while(scanf("%d%d\n",&r,&c) && r){
		for(pL1 = pL2 = i = 0; i < r; i++){
			for(pC1 = pC2 = j = 0; j < c; j++){
				fastint(&v);
				temp = pC1;
				pC1 = max(pC1,v+pC2);
				pC2 = temp;
			}
			temp = pL1;
			pL1 = max(pL1,pC1+pL2);
			pL2 = temp;
		}
		printf("%d\n",pL1);
	}
	return 0;
}
