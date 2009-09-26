/////////////////////////////////
// 11044 - Searching for Nessy
/////////////////////////////////
#include<cstdio>
unsigned int m,n,cnum;
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		scanf("%u %u\n",&m,&n);
		m = (m/3)*(n/3);
		printf("%u\n",m);
	}
	return 0;
}
