/////////////////////////////////
// 11428 - Cubes
/////////////////////////////////
#include<cstdio>
#define MAX 10001
int x,y,cx,cy,aux;
int smaller[MAX];
int bigger[MAX];
int cube(int k){
	return k*k*k;
}
int main(void){
	for(y = 0; y < MAX; smaller[y] = bigger[y] = 0, y++);
	for(y = 1; y < 58; y++){
		cy = cube(y);
		for(x = y+1; (cx = cube(x)) - cy <= 10000; x++){
			aux = cx - cy;
			if(smaller[aux] == 0){
				smaller[aux] = y;
				bigger[aux] = x;
			}
		}
	}
	scanf("%d",&y);
	while(y){
		if(smaller[y] == 0) printf("No solution\n");
		else printf("%d %d\n",bigger[y],smaller[y]);
		scanf("%d",&y);
	}
}