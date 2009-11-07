#include <cstdio>

long long f[55];
int main(void){
	f[1] = 1; f[2] = 2;
	for(int k = 3; k < 55; ++k) f[k] = f[k - 1] + f[k - 2];
	for(int n; scanf("%d",&n)==1 && n; ) printf("%lld\n",f[n]);
	return 0;
}

