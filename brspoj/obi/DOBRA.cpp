#include <cstdio>
int main(void){
	int k, n, t;
	for(t = 1; scanf("%d",&n) && n != -1 ; t++)
		printf("Teste %d\n%d\n\n", t,(k = (1<<n)+1)*k);
	return 0;
}

