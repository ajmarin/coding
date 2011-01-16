/////////////////////////////////
// 10327 - Flip Sort
/////////////////////////////////
#include<cstdio>
#define MAX 1000
int v[MAX];
int i,j,n,aux,flips;
void flip(){
	flips = 0;
	for(i =0; i < n; i++)
		for(j = 0; j < n-i-1; j++)
			if(v[j]>v[j+1]){
				flips++;
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}
int main(void){
	while(scanf("%d",&n)!=EOF){
		for(i= 0; i < n; i++) scanf("%d",&v[i]);
		flip();
		printf("Minimum exchange operations : %d\n",flips);
	}
}
