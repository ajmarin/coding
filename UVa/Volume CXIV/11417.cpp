/////////////////////////////////
// 11417 - GCD
/////////////////////////////////
#include <cstdio>
int Gs[501];
bool sieve[501];
int i,n,j;
int gcd(int a,int b){
	int c = -1;
	while(c!=0){
		c = b%a;
		b = a;
		a = c;
	}
	return b;
}
int main(){
	for(i = 4; i < 500; i+=2) sieve[i] = true;
	for(i = 3; i < 501; i+=2){
		if(!sieve[i]){
			j = i*i;
			if(j < 501) for( ;j < 501; j+=i) sieve[j] = true;
		}
	}
	Gs[0] = 0;
	for(i = 1; i < 501; i++){
		Gs[i] = Gs[i-1];
		if(!sieve[i]) Gs[i] += i-1;
		else for(j = 1; j < i; j++) Gs[i] += gcd(j,i);
	}
	
	
	while(scanf("%d",&n)){
		if(!n) break;
		printf("%d\n",Gs[n]);
	}
	return 0;
}
