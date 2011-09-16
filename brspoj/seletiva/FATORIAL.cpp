#include <cstdio>
#define MAX 1000001
#define K 20000
long long int i, r[MAX];
int inum = 1;
int main(void){
	r[0] = r[1] = 1;
	for(i = 2; i < MAX; i++){
		r[i] = r[i-1]*i;
		while(r[i]%10 == 0) r[i] /= 10;
		r[i] %= 20000;
	}
	while(scanf("%lld",&i)!= EOF)
		printf("Instancia %d\n%lld\n\n",inum++,r[i]%10);
	return 0;
}
