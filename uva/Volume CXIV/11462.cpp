/////////////////////////////////
// 11462 - Age Sort
/////////////////////////////////
#include<cstdio>
#define MAX_NUM 100
#define MAX 2000000
int v[MAX];
int C[MAX_NUM];
int size,i;
void csort(){
	int pos = 0;
	for(i = 0; i < MAX_NUM; i++) C[i] = 0;
	for(i = 0; i < size; i++) C[v[i]]++;	
	for(i = 0; i < MAX_NUM; i++)
		while(C[i] > 0){
			v[pos++] = i;
			C[i]--;
		}
}
int main(){
	while(true){
		scanf("%d",&size);
		if(size == 0) break;
		for(i = 0; i < size; i++) scanf("%d",&v[i]);
		csort();
		for(i = 0; i < size-1; i++) printf("%d ",v[i]);
		printf("%d\n",v[size-1]);
	}
	return 0;
}