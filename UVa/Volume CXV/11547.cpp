/////////////////////////////////
// 11547 - Automatic Answer
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define pos(a) (a < 0? -a: a)
int n,c;
int main(void){
	scanf("%d",&c);
	while(c--){
		scanf("%d",&n);
		printf("%d\n",pos((315*n+36962)%100/10));
	}
}