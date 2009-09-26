/////////////////////////////////
// 11567 - Moliu Number Generator
/////////////////////////////////
#include<cstdio>
unsigned int n;
unsigned int calc(unsigned int k){
	if(k<4) return k;
	if(k&1){
		if(!((k+1)%4)) return 3+calc((k+1)>>2);
		else return 3+calc((k-1)>>2);
	} else return 1+calc(k>>1);
}
int main(void){
	while(scanf("%u",&n)!=EOF){
		printf("%u\n",calc(n));
	}
	return 0;
}
