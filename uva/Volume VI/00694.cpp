/////////////////////////////////
// 00694 - The Collatz Sequence
/////////////////////////////////
#include<cstdio>
#include<climits>
int i;
unsigned int A,chain,cnum,lim;
int main(void){
	while(scanf("%d %u",&i,&lim)){
		if(i == -1) break;
		A = i;
		printf("Case %u: A = %u, limit = %u, number of terms = ",++cnum,A,lim);
		chain = 1;
		lim = (lim-1)/3;
		while(A!=1){
			if(A&1){
				if(A > lim) break;
				A = (3*A + 1)>>1;
				chain++;
			} else A>>=1;
			chain++;
		}
		printf("%u\n",chain);
	}
	return 0;
}
