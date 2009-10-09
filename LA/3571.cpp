#include <cstdio>
#include <cstring>

int gcd(int a, int b) { 
	if(a % b == 0) return b;
	return gcd(b, a % b);
} 

int tot[1001];
int main(void){
	memset(tot, 0, sizeof(tot));
	for(int i = 1; i < 1001; ++i)
		for(int j = i+1; j < 1001; ++j)
			if(gcd(i,j) == 1) tot[j]++;
	for(int i = 2; i < 1001; ++i)
		tot[i] += tot[i-1];
	int T, N;
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		scanf("%d",&N);
		int s = tot[N];
		printf("%d %d %d\n",++cnum,N,2*s + 3);
	}

	return 0;
}

