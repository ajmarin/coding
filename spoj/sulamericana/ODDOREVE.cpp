#include <cstdio>
#include <cstdlib>
int main(void){
	int i, k, n, v1, v2;
	while(scanf("%d",&n) && n){
		for(v1 = i = 0; i < n; i++) scanf("%d",&k), v1 += k&1;
		for(v2 = i = 0; i < n; i++) scanf("%d",&k), v2 += !(k&1);
		printf("%d\n",abs(v1-v2));
	}
	return 0;
}
