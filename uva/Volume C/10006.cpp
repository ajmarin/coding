/////////////////////////////////
// 10006 - Carmichael Numbers
/////////////////////////////////
#include<cstdio>
bool carmichael[65001];
int i,n;
int main(void){
	carmichael[561] = carmichael[1105] = carmichael[1729] = carmichael[2465] = carmichael[2821] = 1;
	carmichael[6601] = carmichael[8911] = carmichael[10585] = carmichael[15841] = carmichael[29341] = 1;
	carmichael[41041] = carmichael[46657] = carmichael[52633] = carmichael[62745] = carmichael[63973] = 1;
	while(scanf("%d",&n) && n){		
		if(carmichael[n]) printf("The number %d is a Carmichael number.\n",n);
		else printf("%d is normal.\n",n);
	}
	return 0;
}

