/////////////////////////////////
// 00357 - Let Me Count The Ways
/////////////////////////////////
#include<cstdio>
#include<cmath>
#include<cstring>
unsigned int i,j,n;
unsigned int coin[] = {1,5,10,25,50};
unsigned long long int p[30001];
int main(void){
	memset(p,0,sizeof(p));
	p[0] = 1;
	for(i = 0; i < 5; i++)
		for(j = coin[i]; j < 30001; j++)
			p[j] += p[j-coin[i]];
	while(scanf("%u\n",&n)!=EOF)
		if(n > 4)	
		printf("There are %llu ways to produce %u cents change.\n",p[n],n);
		else printf("There is only 1 way to produce %u cents change.\n",n);
	return 0;
}
