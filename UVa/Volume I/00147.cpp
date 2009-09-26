/////////////////////////////////
// 00147 - Dollars
/////////////////////////////////
#include<cstdio>
#include<cmath>
#include<cstring>
unsigned int a,b,i,idx,j;
unsigned int coin[] = {1,2,4,10,20,40,100,200,400,1000,2000};
unsigned long long int poss[6001];
float n;
int main(void){
	memset(poss,0,sizeof(poss));
	poss[0] = 1;
	for(i = 0; i < 11; i++)
		for(j = coin[i]; j < 6001; j++)
			poss[j] += poss[j-coin[i]];
	while(scanf("%u.%u\n",&a, &b) && (a||b))
		printf("%3u.%02u%17llu\n",a,b,poss[(100*a+b)/5]);
	return 0;
}
