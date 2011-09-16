#include <cstdio> 
int main(void){
	int n, tnum = 1;
	while(scanf("%d",&n) && n) printf("Teste %d\n%d\n\n",tnum++,(1<<n)-1);
	return 0;
}
