/////////////////////////////////
// 00530 - Binomial Showdown
/////////////////////////////////
#include<cstdio>
long double n,k,sum,c;
int main(void){
	while(scanf("%Lf %Lf",&n,&k)){
		if(n==0) break;
		if(k> n-k) k=n-k;
		for(sum=1,c=k;c>0;c--,n--) sum*=n;
		for(;k>1;k--) sum/=k;
		printf("%.0Lf\n",sum);
	}
}
