#include<cstdio>
int main(void){
	int n;
	while(scanf("%d",&n) && n) printf("%d\n",n*(n+1)*(2*n+1)/6);
	return 0;
}