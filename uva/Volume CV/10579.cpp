/////////////////////////////////
// 10579 - Fibonacci Numbers
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
char fib[4788][1005], ans[1005];
bool end;
unsigned int i,len,n;
void add(int k){
	unsigned int c=0,d,i;
	int l1 = strlen(fib[k-1]),l2 = strlen(fib[k-2]);
	for(i = l1; i < l2; i++) fib[k-1][i] = '0';
	for(i = l2; i < l1; i++) fib[k-2][i] = '0';
	for(i = 0; i < l1 || i < l2; i++){
		c = fib[k-1][i]+fib[k-2][i]-'0'-'0'+c;
		fib[k][i] = c%10+'0'; c/=10;
	}
	if(c) fib[k][i++] = '1';
	fib[k][i] = 0;
	for(i = l1; i < l2; i++) fib[k-1][i] = 0;
	for(i = l2; i < l1; i++) fib[k-2][i] = 0;
}
int main(void){
	strcpy(fib[1],"1"); strcpy(fib[2],"1");
	end = 0; i = 3;
	for(i = 3; i != 4788; add(i++));
	while(scanf("%u",&n)!=EOF){
		len = strlen(fib[n]);
		for(i = len; i; i--) ans[len-i] = fib[n][i-1];
		ans[len] = 0;
		puts(ans);
	}
	return 0;
}
