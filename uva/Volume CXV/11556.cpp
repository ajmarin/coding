/////////////////////////////////
// 11556 - Best Compression Ever
/////////////////////////////////
#include<cstdio>
unsigned long long int a,b;
const char *y = "yes", *n = "no";
int main(void){
	while(scanf("%llu %llu",&a,&b)!=EOF)
		if(a < 1LLU<<(b+1)) puts(y);
		else puts(n);
	return 0;
}
