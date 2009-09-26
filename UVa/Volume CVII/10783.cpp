/////////////////////////////////
// 10783 - Odd Sum
/////////////////////////////////
#include<cstdio>
int a,b,c,ncase,sum;
int main(void){
	while(scanf("%d",&c)!=EOF){
		ncase =1;
		while(c){
			scanf("%d\n%d",&a,&b);
			c--;
			if(a%2==0) a++;
			for(sum = 0; a <= b; sum+=a,a+=2);
			printf("Case %d: %d\n",ncase,sum);
			ncase++;
		}
	}
	return 0;
}
