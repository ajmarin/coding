/////////////////////////////////
// 00278 - Chess 
/////////////////////////////////
#include<cstdio>
#include<cmath>
float a,b;
char c;
int n;
int main(void){
	scanf("%d\n",&n);
	while(n){
		n--;
		scanf("%c %f %f\n",&c,&a,&b);
		if(c == 'k') printf("%.0f\n",ceil(a*b/2.0));
		else if(c == 'K') printf("%.0f\n",(ceil(a/2.0)*ceil(b/2.0)));
		else printf("%.0f\n",(a < b? a:b));
	}
}