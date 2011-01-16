#include <cstdio>

#define LIM 46341

unsigned int sq[LIM];
int main(void){
	int a, b, c, i, T;
	for(i = 0; i < LIM; i++) sq[i] = i*i;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&a,&b);
		a = (b-a);
		if(a == 0){ puts("0"); continue; }
		for(b = 1, i = LIM; b < i; ){
			c = (b+i)>>1;
			if(sq[c] > a) i = c; else b = c+1;
		}
		printf("%d\n",(a-sq[--i]+i-1)/i + (i<<1) - 1);
	}
	return 0;
}
