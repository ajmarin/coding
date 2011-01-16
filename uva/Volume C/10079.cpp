/////////////////////////////////
// 10079 - Pizza Cutting
/////////////////////////////////
#include<cstdio>
int k;
long long int n;
int main(void){
	scanf("%d",&k);
	while(k >= 0){
		n = k;
		n = n*(n+1)/2+1;
		printf("%lld\n",n);		
		scanf("%d",&k);
	}
}