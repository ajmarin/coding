/////////////////////////////////
// 10346 - Peter's Smoke
/////////////////////////////////
#include<cstdio>
int ciggs,n,k,butts;
int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		ciggs = n;
		while(n >= k){
			butts = n%k;
			n/=k;
			ciggs+= n;
			n+=butts;
		}
		printf("%d\n",ciggs);
	}
	return 0;
}