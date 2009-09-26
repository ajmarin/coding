/////////////////////////////////
// 11387 - The 3-Regular Graph
/////////////////////////////////
#include<stdio.h>
#include<string.h>
unsigned int i,j,k,n;
const char *imp = "Impossible";
int main(void) {
	int i,j,n;	
	while(scanf("%u",&n) && n){
		if(n > 3 && !(n%2)){
			printf("%u\n",(3*n)>>1);
			k = n>>1;
			for(i = 1; i < k; i++){
				printf("%u %u\n",i,i+1);
				printf("%u %u\n",i,k+i);
			}
			printf("1 %u\n",n);
			printf("%u %u\n",k,n);
			while(i < n)
				printf("%u %u\n",i,i+1), i++;			
		} else puts(imp);
	}
}

