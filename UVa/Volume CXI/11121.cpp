/////////////////////////////////
// 11121 - Base -2
/////////////////////////////////
#include<cstdio>
#include<algorithm>
char q[100], top;
unsigned int i,t;
int n, res;
int main(void){
	scanf("%u",&t);
	for(i = 1; t--; i++){
		scanf("%d",&n); top = 0;
		do{
			res = n/-2;
			if(n<0 && n&1) res++;
			q[top++] = (n-(res*-2))+'0';
			n = res;
		}while(n);
		q[top] = 0;
		std::reverse(q,q+top);
		printf("Case #%u: %s\n",i,q);
	}
	return 0;
}
