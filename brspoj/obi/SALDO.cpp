#include <cstdio>
int a, b, f, i, l, max, n, pmax, saldo, s;
int main(void){
	for(int t = 1; scanf("%d",&n) && n; t++){
		saldo = max = f = l = pmax = -1;
		for(i = 1; i <= n; i++){
			scanf("%d%d",&a,&b);
			if(saldo < 0) s = i, saldo = 0;
			saldo += (a - b);
			if(saldo > max || (saldo == max && i - s > pmax)){
				max = saldo;
				f = s, l = i;
				pmax = l - f;
			}
		}
		if(max > 0) printf("Teste %d\n%d %d\n\n",t,f,l);
		else printf("Teste %d\nnenhum\n\n",t);
	}
	return 0;
}
