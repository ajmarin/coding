/////////////////////////////////
// 11069 - A Graph Problem
/////////////////////////////////
#include<cstdio>
unsigned int ways[77],i;
int main(void){
	ways[1] = 1;
	ways[2] = ways[3] = 2;
	for(i = 4; i != 77; i++)
		ways[i] = ways[i-2]+ways[i-3];
	while(scanf("%u",&i)!=EOF) printf("%u\n",ways[i]);
	return 0;
}

