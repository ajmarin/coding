/////////////////////////////////
// 00594 - One Little, Two Little, Three Little Endians
/////////////////////////////////
#include<cstdio>
#include<algorithm>
int a, i, n;
bool bin[33];
int main(void){
	bin[33] = 0;
	while(scanf("%d",&n)!=EOF){
		a = n; i = 0;
		a = 0;
		for (i=0; i<32; i++)
			if (n&(1<<i)) a |= 1<<((3-(i>>3))<<3)+(i%8);	
	    printf("%d converts to %d\n",n,a);
	}
	return 0;
}
	
