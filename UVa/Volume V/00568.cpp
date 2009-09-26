/////////////////////////////////
// 00568 - Just the Facts
/////////////////////////////////
#include<cstdio>
unsigned int i,n,last;
int main(void){
	while(scanf("%d",&n)==1){
		for(last = i = 1; !(i>n); ++i){
			last *= i;
			while(!(last%10)) last/=10;
			if(last>20000) last%=20000;			
		}
		printf("%5u -> %u\n",n,last%10);
	}
	return 0;
}
