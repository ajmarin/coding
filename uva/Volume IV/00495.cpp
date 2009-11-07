/////////////////////////////////
// 00495 - Fibonacci Freeze
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<algorithm>
bool calc[5001];
char val[5001][1200], line[1200];
short int n,i;
void add(int k){
	int c=0,d,i;
	int l1 = strlen(val[k-1]),l2 = strlen(val[k-2]);
	for(i = l1; i < l2; i++) val[k-1][i] = '0';
	for(i = l2; i < l1; i++) val[k-2][i] = '0';
	for(i = 0; i < l1 || i < l2; i++){
		d = val[k-1][i]+val[k-2][i]-'0'-'0'+c;		
		c = d/10; d%=10;
		val[k][i] = d+'0';
	}
	if(c) val[k][i++] = '1';
	val[k][i] = 0;
	for(i = l1; i < l2; i++) val[k-1][i] = 0;
	for(i = l2; i < l1; i++) val[k-2][i] = 0;
}
void fib(short int k){
	if(!calc[k]) {
		calc[k] = 1; 
		fib(k-1); 
		fib(k-2);
		add(k);
	}
}
int main(void){
	memset(val,0,sizeof(val));
	memset(calc,0,sizeof(calc));
	val[0][0] = '0';
	val[1][0] = val[2][0] = '1';	
	calc[0] = calc[1] = calc[2] = 1;
	while(scanf("%hd",&n)==1){
		fib(n);				
		short int len = strlen(val[n])-1;
		for(i = len; i > -1; i--) line[len-i] = val[n][i];
		line[len+1] = 0;
		printf("The Fibonacci number for %hd is %s\n",n,line);
	}
	return 0;
}
