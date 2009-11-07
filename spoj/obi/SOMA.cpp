#include <cstdio>
int main(void){
	int n, sum = 0, v;
	scanf("%d",&n);
	while(n--)
		scanf("%d",&v), sum += v;
	printf("%d\n",sum);
	return 0;
}
