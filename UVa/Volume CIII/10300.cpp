/////////////////////////////////
// 10300 - Ecological Premium
/////////////////////////////////
#include<cstdio>
int n,f;
long long a,b,c;
long long sum;
int main(void){
	scanf("%d",&n);
	while(n){
		n--;
		scanf("%d",&f);
		sum = 0;
		while(f){
			f--;
			scanf("%d %d %d",&a,&b,&c);
			if(b==0) continue;
			sum += a*c;
		}		
		printf("%lld\n",sum);
	}
	return 0;
}
