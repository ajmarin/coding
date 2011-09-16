#include<cstdio>
int fat[13] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int main(void){
	int n;
	scanf("%d",&n);
	printf("%d\n",fat[n]);
	return 0;
}