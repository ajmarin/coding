#include<stdio.h>
int i,n, winner,aux;
int v[100001];
int main(void){
	scanf("%d",&n);
	while(n){
		for(i = 1; i <= n; scanf("%d",&v[i]),i++);
		winner = 1;
		for(i = 1; i <= n;)
			if(v[i] != i){
				aux = v[i];
				v[i] = v[v[i]];
				v[aux] = aux;
				winner = !winner;
			}
			else i++;
		if(winner) printf("Carlos\n");
		else printf("Marcelo\n");
		scanf("%d",&n);
	}
	return 0;
}
