/////////////////////////////////
// 11137 - Ingenuous Cubrency
/////////////////////////////////
#include<cstdio>
long long ways[10000];
unsigned int i,j;
int coins[] = {1,8,27,64,125,216,343,512,729,1000,
1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
int main(void){
	ways[0] = 1;
	for(i = 0; i < 21; i++)
		for(j = coins[i]; j < 10000; j++)
			ways[j] += ways[j-coins[i]];
	while(scanf("%u",&i)!=EOF) printf("%lld\n",ways[i]);
}
