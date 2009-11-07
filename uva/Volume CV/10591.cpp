/////////////////////////////////
// 10591 - Happy Number
/////////////////////////////////
#include<cstdio>
unsigned short int sumsqod[800];
bool happy[] = {0,1,0,0,0,0,0,1,0,0};
unsigned int cnum,init,n,tnum;
unsigned int fsqod(unsigned int k){
	unsigned int a,ret=0;
	while(k){
		a = (k%10);
		ret += a*a;
		k/=10;
	}
	return ret;
}
unsigned int sqod(unsigned int k){
	if(sumsqod[k]) return sumsqod[k];
	unsigned int a,ret=0;
	while(k){
		a = (k%10);
		ret += a*a;
		k/=10;
	}
	sumsqod[n] = ret;
	return ret;
}
int main(void){
	scanf("%u\n",&tnum);
	while(tnum--){
		scanf("%u",&n);
		cnum++;
		init = n;
		n = fsqod(n);
		while(n > 9) n = sqod(n);
		if(happy[n]) printf("Case #%u: %u is a Happy number.\n",cnum,init);
		else printf("Case #%u: %u is an Unhappy number.\n",cnum,init);
	}
	return 0;
}
