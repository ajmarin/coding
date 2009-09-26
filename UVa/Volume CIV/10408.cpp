/////////////////////////////////
// 10408 - Farey sequences
/////////////////////////////////
#include<cstdio>
unsigned int a,b,c,count,d,k,n,preva,prevb,show;
void farey(){
	a = count = 0; b = c = 1; d = n;
	while (count != show){
		k = (n + b)/d;
		preva = a;
		prevb = b;
		a = c; b = d;
		c = k*c-preva; d = k*d-prevb;
		count++;
	}
	printf("%u/%u\n",a,b);
}
int main(void){
	while(scanf("%u %u",&n,&show)!=EOF) farey();
	return 0;
}
