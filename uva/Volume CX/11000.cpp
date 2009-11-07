/////////////////////////////////
// 11000 - Bee
/////////////////////////////////
#include<cstdio>
unsigned int f[45],i,m[45];
int k;
int main(void){
	m[0] = 0; f[0] = 1;
	for(i = 1; i < 45; i++)
		m[i] = f[i-1], f[i] = m[i-1]+f[i-1]+1;
	while(scanf("%d",&k) && k != -1)
		printf("%u %u\n",m[k],f[k]);
	return 0;
}

