/////////////////////////////////
// 11332 - Summing Digits
/////////////////////////////////
#include<cstdio>
char sum[100];
unsigned int n;
unsigned int fsod(unsigned int k){
	unsigned int ret = 0;
	while(k){
		ret += k%10;
		k/=10;
	}
	return ret;
}
unsigned int sod(unsigned int k){
	if(sum[k]) return sum[k];
	unsigned int ret = 0;
	while(k){
		ret += k%10;
		k/=10;
	}
	sum[n] = ret;
	return ret;
}
int main(void){
	while(scanf("%u",&n) && n){
		n = fsod(n);
		while(n>9){
			n = sod(n);
		}
		printf("%u\n",n);
	}
	return 0;
}

