/////////////////////////////////
// 00756 - Biorhythms
/////////////////////////////////
#include<cstdio>
int main(void){
	int a,b,c,d,sum,m,w,i=1;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)==4 && a+b+c+d!=-4){
		sum=0;
		a=a%23;	b=b%28; c=c%33;		
		sum=a*6*924+b*-9*759+c*2*644;
		while(sum<0) sum+= 21252;
		sum%=21252;
		if(sum <= d) sum+= 21252;		
		printf("Case %d: the next triple peak occurs in %d days.\n",i++,sum-d);
	}
}

