/////////////////////////////////
// 10370 - Above Average
/////////////////////////////////
#include<cstdio>
#define MAX 1000
int grades[MAX];
float m,n,above;
float ans;
int c,i;
int main(void){
	scanf("%d",&c);
	while(c){
		c--;
		m = above = 0.0;
		scanf("%f",&n);
		for(i = 0; i < n; scanf("%d",&grades[i]),m+=grades[i],i++);
		m/=n;
		//printf("m = %.3f\n",m);
		for(i = 0; i < n; i++) if(grades[i] > m) above++;
		ans = 100*above/n;
		printf("%.3f%\n",ans);		
	}
	return 0;
}
