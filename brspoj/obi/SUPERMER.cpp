#include <cstdio>
#include <algorithm>
int i, n;
int vx[1000] ,vy[1000];
int main(void){
	for(int t = 1; scanf("%d",&n) && n; t++){
		for(i = 0; i < n; i++) scanf("%d%d",&vx[i],&vy[i]);
		std::sort(vx,vx+n);
		std::sort(vy,vy+n);
		n >>= 1;
		printf("Teste %d\n%d %d\n\n",t,vx[n],vy[n]);
	}
	return 0;
}

