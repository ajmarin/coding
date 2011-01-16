/////////////////////////////////
// 00264 - Count on Cantor 
/////////////////////////////////
#include<cstdio>

#include<cmath>
int ntri, tri, n;
int nup(int k){
	return (int)ceil((-1+sqrt(1+8*k))/2);
}
int main(void){
	while(scanf("%d",&n)!=EOF){
		ntri = nup(n);
		tri = ntri*(ntri+1)/2;
		if(ntri&1) printf("TERM %d IS %d/%d\n",n,1+(tri-n),ntri-(tri-n));
		else printf("TERM %d IS %d/%d\n",n,ntri-(tri-n),1+(tri-n));
	}
}
