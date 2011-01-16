/////////////////////////////////
// 11172 - Relational Operator
/////////////////////////////////
#include<cstdio>
unsigned int a,b,cnum;
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		scanf("%u %u\n",&a,&b);
		if(a < b) printf("<\n");
		else if(a > b) printf(">\n");
		else printf("=\n");
	}
	return 0;
}
