#include<cstdio>
#include<cstring>
int c, i, j, n;
long long acc, sum, v[100025];
int main(void){
	scanf("%d",&c);
	while(c--){
		sum = 0;
		scanf("%d",&n);
		for(i = 0; i < n; i++) scanf("%lld",&v[i]), acc += v[i];
		for(i = 0; i < n; i++){
			sum += ((acc%1300031)*(v[i]%1300031))%1300031;
			acc -= v[i];
		}
		printf("%lld\n",sum%1300031);
	}
	return 0;
}
