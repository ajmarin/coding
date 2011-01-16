/////////////////////////////////
// 11185 - Ternary
/////////////////////////////////
#include<cstdio>
#include<cstdlib>
#define MAXCAND 8
int n;
char ans[30],idx;
int main(void){
	ans[29] = 0;
	while(scanf("%d",&n) && n >= 0){
		idx = 29;
		do{
			ans[--idx] = ('0'+n%3);
			n/=3;
		} while(n);
		puts(ans+idx);
	}
}

