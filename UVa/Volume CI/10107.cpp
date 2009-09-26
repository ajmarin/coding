/////////////////////////////////
// 10107 - What is the Median?
/////////////////////////////////
#include<cstdio>
#include<algorithm>
#define MAX 10000
int i,n = 0,x;
int v[MAX];
int main(void){
	while(scanf("%d",&v[n])!=EOF){	
		n++;		
		if(n > 1) if(v[n-1] < v[n-2]) std::sort(v,v+n);
		/*printf("Vector: ");
		for(i = 0; i < n; i++) printf("%d,",v[i]);
		printf("\n");*/
		if(n%2) printf("%d\n",v[n/2]);
		else printf("%d\n",(v[n/2-1]+v[n/2])/2);
	}
}
		
