/////////////////////////////////
// 00369 - Combinations
/////////////////////////////////
#include<cstdio>
int a,b,i;
double res;
void doComb(){
	res = 1;
	for(i = a; i > b; i--){
		res*=i;
		res/=(i-b);
	}
}
int main(void){
	scanf("%d",&a);
	while(a){
		scanf("%d",&b);
		doComb();
		printf("%d things taken %d at a time is %.0lf exactly.\n",a,b,res);
		scanf("%d",&a);
	}
	return 0;
}

