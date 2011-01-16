/////////////////////////////////
// 10642 - Can You Solve It?
/////////////////////////////////
#include<cstdio>
typedef unsigned long long int ULLI;
ULLI x1,x2,y1,y2;
unsigned int cnum,tnum;
ULLI rank(ULLI a, ULLI b){
	return((a+b+1)*(a+b+2)/2 - b);
}
int main(void){
	scanf("%u",&cnum);
	while(cnum--){
		tnum++;
		scanf("%llu %llu %llu %llu",&x1,&y1,&x2,&y2);
		printf("Case %u: %llu\n",tnum,rank(x2,y2)-rank(x1,y1));
	}
	return 0;
}
