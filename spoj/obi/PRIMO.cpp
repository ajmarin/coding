#include <cstdio>
#include <cmath>
int n;
int main(void){
	scanf("%d",&n);
	if(n < 0) n = -n;
	int i, lim = (int)(sqrt(n)+1);
	bool primo = !(n == 1 || (!(n&1) && n != 2));
	for(i = 3; primo && i < lim; i+=2)
		primo = n%i;
	if(primo) puts("sim");
	else puts("nao");
	return 0;
}
