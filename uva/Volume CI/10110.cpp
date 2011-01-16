/////////////////////////////////
// 10110 - Light, More Light
/////////////////////////////////
#include<cstdio>
#include<cmath>
long long i,n,root;

bool on;
int main(void){	
	scanf("%lld",&n);
	while(n){
		on = 0;
		root = (int)sqrt(n);
		on = (root*root == n);		
		if(on) printf("yes\n");
		else printf("no\n");
		scanf("%lld",&n);
	}
}
