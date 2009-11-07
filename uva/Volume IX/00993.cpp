/////////////////////////////////
// 00993 - Product of digits
/////////////////////////////////
#include<cstdio>
#include<algorithm>
unsigned int n,casenum;
char num[15], occ[4], top;
int main(void){
	scanf("%u\n",&casenum);	
	while(casenum--){
		occ[0] = occ[1] = occ[2] = occ[3] = top = 0;
		scanf("%u\n",&n);
		if(n==1){printf("1\n"); continue;}
		if(!n){printf("10\n"); continue;}
		while(!(n%2)) occ[0]++,n/=2;
		while(!(n%3)) occ[1]++,n/=3;
		while(!(n%5)) occ[2]++,n/=5;
		while(!(n%7)) occ[3]++,n/=7;
		if(n!=1){printf("-1\n"); continue;}
		while(occ[1] > 1) num[top++] = '9', occ[1] -=2;
		while(occ[0] > 2) num[top++] = '8', occ[0] -= 3;
		while(occ[3]--) num[top++] = '7';
		while(occ[0] && occ[1]) num[top++] = '6', occ[0]--, occ[1]--;
		while(occ[2]--) num[top++] = '5';
		if(occ[0] > 1) num[top++] = '4', occ[0] = 0;		
		if(occ[1]) num[top++] = '3';
		if(occ[0]) num[top++] = '2';
		num[top] = 0;
		std::reverse(num,num+top);
		puts(num);
	}
	return 0;
}	