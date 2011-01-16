/////////////////////////////////
// 11207 - The easiest way
/////////////////////////////////
#include<cstdio>
#define MAX(a,b) (a>b?a:b)
unsigned int i,n,paper,x,y;
float side, biggest;
int main(void){
	while(scanf("%u\n",&n) && n){
		biggest = 0;
		for(i = 0; i != n ; i++){
			scanf("%u %u\n",&x,&y);
			if(x>y) x ^= y ^= x ^= y;			
			if(y >= x*4) side = x;
			else side = MAX(y/4.00,x/2.00);
			if(side > biggest) biggest = side, paper = i+1;
		}
		printf("%u\n",paper);
	}
	return 0;
}
		
