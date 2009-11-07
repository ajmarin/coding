/////////////////////////////////
// 10193 - All You Need Is Love
/////////////////////////////////
#include<cstdio>
#include<cstring>
char a[32], b[32];
unsigned int cnum,i,k,w,x,y;
char lena, lenb, it;
unsigned int gcd(unsigned int a, unsigned int b){
	if(a) return gcd(b%a,a);
	return b;
}
int main(void){
	scanf("%u\n",&cnum);
	for(i = 0; i != cnum;){
		i++;
		gets(a);
		gets(b);
		for(x = 0,w = 1, it = strlen(a); it; it--) 
			x += w*(a[it-1]-'0'),w*=2;
		for(y = 0,w = 1, it = strlen(b); it; it--) 
			y += w*(b[it-1]-'0'),w*=2;
		if(y>x) k = gcd(x,y);
		else k = gcd(y,x);
		if(k!=1) printf("Pair #%u: All you need is love!\n",i);
		else printf("Pair #%u: Love is not all you need!\n",i);
	}
	return 0;
}
		
