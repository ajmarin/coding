/////////////////////////////////
// 00412 - Pi
/////////////////////////////////
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?b:a)
typedef unsigned short int USI;

bool prime[45000];
USI count,i,j,n,set[50];
double pi;
USI gcd(USI a,USI b){
	if(a && a!=b){
		if(prime[b]) return 1;
		else return gcd(b%a,a);
	}
	else return b;
}
int main(){
	memset(prime,1,sizeof(prime));
	int lim = 200;
	prime[0] = prime[1] = 0;
	for(i = 4; i < 40000; i+=2) prime[i] = 0;
	for(i = 3; i < lim; i+=2)
		if(prime[i]) for(j = i*i; j < 40000; j+=i) prime[j] = 0;	
	while(scanf("%u",&n) && n){
		for(i = 0; i < n; i++) scanf("%u",&set[i]);
		std::sort(set,set+n);
		for(count = i = 0; i < n; i++)
			for(j = i+1; j < n; j++)
				if(gcd(set[i],set[j]) == 1) count++;
		if(count) printf("%.6lf\n",sqrt(3.000000*n*(n-1)/count));
		else printf("No estimate for this data set.\n");
	}
}
