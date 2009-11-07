/////////////////////////////////
// 10550 - Combination Lock
/////////////////////////////////
#include<cstdio>
unsigned int a,b,c,d;
unsigned short turn, ans;
int main(void){
	while(scanf("%u %u %u %u\n",&a,&b,&c,&d) && (a||b||c||d)){
		ans = 1080;
		if(b>a) ans += (40+a-b)*9;
		else ans += (a-b)*9;
		if(b>c) ans += (40+c-b)*9;
		else ans += (c-b)*9;
		if(d>c) ans += (40+c-d)*9;
		else ans += (c-d)*9;				
		printf("%hu\n",ans);
	}
}

