/////////////////////////////////
// 10055 - Hashmat the Brave Warrior 
/////////////////////////////////
#include<cstdio>
int main(){
	register unsigned long long a,b;
	while(scanf("%llu %llu",&a,&b)!=EOF)
		printf("%llu\n",(b>a)?b-a:a-b);
}
