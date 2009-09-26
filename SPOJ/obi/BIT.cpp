#include<cstdio>
int main(void){
	int u[4];
	for(int a = 1, n; scanf("%d",&n) && n; a++){
		u[0] = u[1] = u[2] = u[3] = 0;
		if(n>49) u[0] = n/50, n -= u[0]*50;
		if(n>9) u[1] = n/10, n -= u[1]*10;
		if(n>4) u[2] = n/5, n -= u[2]*5;
		u[3] = n;
		printf("Teste %d\n%d %d %d %d\n",a,u[0],u[1],u[2],u[3]);
	}
	return 0;
}