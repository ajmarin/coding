/////////////////////////////////
// 00374 - Big Mod
/////////////////////////////////
#include<cstdio>
typedef unsigned long long int ULL;
ULL b,m,p,r;
ULL pwab5(ULL b,ULL p, ULL m) {
	r=1;
	while(p)
	{
		if(p%2) r=(r*b)%m;
		b=(b*b)%m;
		p/=2;
	}
	return r;
}
int main(void){
	while(scanf("%llu\n%llu\n%llu\n",&b,&p,&m)!=EOF){
		printf("%llu\n",pwab5(b,p,m));
	}
	return 0;
}
