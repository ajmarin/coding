#include<cstdio>
int aux, cn, i, n, swap, v[10001];
int main(void){
	scanf("%d",&cn);
	while(cn--){
		scanf("%d",&n); swap = 0;
		for(i = 1; i <= n; i++) scanf("%d",&v[i]);
		for(i = 1; i <= n; i++)
			while(v[i] != i){
				aux = v[i];
				v[i] = v[v[i]];
				v[aux] = aux;
				swap++;
			}
		printf("%d\n",swap);
	}
	return 0;
}
