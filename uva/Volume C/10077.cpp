/////////////////////////////////
// 10077 - The Stern-Brocot Number System
/////////////////////////////////
#include<cstdio>
int curr[2],left[2],right[2],a,b,div,cdiv;
int main(void){
	while(scanf("%d %d",&a,&b)){
		if(a == b && b == 1) break;
		curr[0] = right[0] = 1;
		curr[1] = left[1] = 1;
		right[1] = left[0] = 0;
		while(curr[0]!=a || curr[1]!=b){
			if(curr[0]*b < curr[1]*a){
				putchar('R');
				left[0] = curr[0];
				left[1] = curr[1];				
			} else{
				putchar('L');
				right[0] = curr[0];
				right[1] = curr[1];
			}
			curr[0] = left[0]+right[0];
			curr[1] = left[1]+right[1];			
		}
		putchar('\n');
	}
	return 0;
}