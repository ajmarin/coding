/////////////////////////////////
// 11455 - Behold my quadrangle
/////////////////////////////////
#include<cstdio>
unsigned int i,j,n,aux;
unsigned int v[4];
void bubble(){
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4-i-1;j++)
			if(v[j] > v[j+1]){
				aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}
int main(void){
	scanf("%d",&n);
	while(n){
		for(i = 0; i < 4; scanf("%d",&v[i]),i++);
		bubble();
		n--;
		if(v[0]+v[1]+v[2] <= v[3]){
			printf("banana\n");
			continue;
		}
		if(v[0] == 0) printf("banana\n");
		else if(v[0] == v[1]){
			if(v[1] == v[2]){
				if(v[2] == v[3]) printf("square\n");
				else printf("quadrangle\n");
			}
			else if(v[2] == v[3]) printf("rectangle\n");
			else printf("quadrangle\n");
		}
		else printf("quadrangle\n");
	}
	return 0;
}
