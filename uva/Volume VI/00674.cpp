/////////////////////////////////
// 00674 - Coin Change
/////////////////////////////////
#include<cstdio>
#include<cstring>
unsigned short i,j;
unsigned short coin[] = {1,5,10,25,50};
unsigned int poss[7490],n;
int main(void){
	memset(poss,0,sizeof(poss));
	poss[0] = 1;
	for(i = 0; i < 5; i++)
		for(j = coin[i]; j < 7490; j++)
			poss[j] += poss[j-coin[i]];
	while(scanf("%u",&n)==1)
		printf("%u\n",poss[n]);
	return 0;
}