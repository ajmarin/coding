/////////////////////////////////
// 11461 - Square Numbers
/////////////////////////////////
#include<cstdio>
#define MAX 318
int squares[318];
int main(void){
	int i,j, sq = 0, prev_square, a,b,count;
	for(i = 1; i < MAX;i++) squares[i] = i*i;	
	while(scanf("%d %d",&a,&b)){
		if(a == b && b == 0) break;
		count = 0;
		for(i = 0; squares[i] < a; i++);
		for(;squares[i] <= b; count++,i++);
		printf("%d\n",count);
	}
	//for(i = 1; i < MAX; i++) printf("ate %d = %d\n",i,squaresuntil[i]);
	return 0;
}