/////////////////////////////////
// 10499 - The Land of Justice
/////////////////////////////////
#include<cstdio>
long long int n;
int main(void){
	while(scanf("%lld\n",&n) && n>0) 
		if(n!=1) printf("%llu%%\n",n*25);
		else printf("0%%\n");
	return 0;
}
	
