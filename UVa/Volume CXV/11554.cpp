/////////////////////////////////
// 11554 - Hapless Hedonism
/////////////////////////////////
#include<cstdio>
unsigned short int t;
unsigned long long int i, triangles[1000001];
int main(void){
	triangles[3] = 0;
	for(i = 4; i < 1000001; i++)
		if(i&1) triangles[i] = (i-1)*(i-3)/4 + triangles[i-1];
		else triangles[i] = (i-2)*(i-2)/4 + triangles[i-1];
	scanf("%hu",&t);	
	while(t--)
		scanf("%llu",&i), printf("%llu\n",triangles[i]);
	return 0;
}
