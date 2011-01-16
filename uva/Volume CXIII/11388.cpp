/////////////////////////////////
// 11388 - GCD LCM
/////////////////////////////////
#include<cstdio>
unsigned int a,b,tnum;
int main(void){
	scanf("%u",&tnum);
	while(tnum--){
		scanf("%u %u",&a,&b);
		if(!(b%a)) printf("%u %u\n",a,b);
		else printf("-1\n");
	}
	return 0;
}
