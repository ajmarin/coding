/////////////////////////////////
// 10812 - Beat the Spread!
/////////////////////////////////
#include<cstdio>
int sum,dif,a,cases;
int main(void){
	scanf("%d",&cases);
	while(cases){
		cases--;
		scanf("%d %d",&sum,&dif);
		a = (sum+dif)/2;		
		if(sum < dif || (sum&1 && !(dif&1)) || (!(sum&1) && dif&1)) printf("impossible\n");
		else if(a > sum-a) printf("%d %d\n",a,sum-a);
		else printf("%d %d\n",sum-a,a);
	}
	return 0;
}				 
