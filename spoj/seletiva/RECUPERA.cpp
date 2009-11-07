#include <cstdio>
int ans, i, n, sum, v[100];
int main(void){
	for(int inst = 1; scanf("%d",&n)==1; inst++){
		printf("Instancia %d\n",inst);
		ans = -1;
		for(i = 0; i < n; i++) scanf("%d",&v[i]);
		for(sum = i = 0; i < n; i++){
			if(sum == v[i]){ ans = i; break; }
			sum += v[i];
		}
		if(ans == -1) puts("nao achei\n");
		else printf("%d\n\n",v[ans]);
	}
	return 0;
}
