/////////////////////////////////
// 00299 - Train Swapping 
/////////////////////////////////
#include<cstdio>
#define MAX 50
int v[50];
int i, j,k,size, cases,swaps,aux;
void bubble(){
	for(j = 0; j < size; j++)
		for(k = 0; k < size-1-j; k++)
			if(v[k] > v[k+1]){
				aux = v[k];
				v[k] = v[k+1];
				v[k+1] = aux;
				swaps++;
			}	
}
int main(void){
	scanf("%d",&cases);
	for(i = 0; i < cases; i++){
		scanf("%d",&size);
		swaps = 0;
		for(j = 0; j < size; j++) scanf("%d",&v[j]);
		bubble();
		printf("Optimal train swapping takes %d swaps.\n",swaps);
	}
	return 0;
}