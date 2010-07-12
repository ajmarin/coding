/////////////////////////////////
// 00913 - Joana and the Odd Numbers
/////////////////////////////////
#include<cstdio>
unsigned long long int k;
int main(void){
	while(scanf("%llu",&k)==1){
		k = (k*(k+2)-5)/2*3;
		printf("%llu\n",k);
	}
	return 0;
}